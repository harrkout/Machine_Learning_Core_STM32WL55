/*  ******************************************************************************\
 * /------------------------------------------------------------------------------/
 * |-- Title      : Sensor Hub v3.0 library
 * |-- Project    : General
 * |#----------------------------------------------------------------------------#
 * |-- File       : shub_v3_0.c
 * |-- Author     : Othon Tomoutzoglou  <otto@hmu.gr>, Dimitris Bakoyiannis <dbakoyiannis@hmu.gr>
 * |-- Company    : Hellenic Mediterranean University, department of
 * |--              Electrical & Computer Engineering, ISCA-lab
 * |-- URL        : https://isca.hmu.gr/
 * |-- Created    : 2022-06-16
 * |-- Last update:
 * |-- License    :
 * |--   This program is free software: you can redistribute it and/or modify
 * |--   it under the terms of the GNU General Public License as published by
 * |--   the Free Software Foundation, either version 3 of the License, or
 * |--   (at your option) any later version.
 * |--
 * |--   This program is distributed in the hope that it will be useful,
 * |--   but WITHOUT ANY WARRANTY; without even the implied warranty of
 * |--   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * |--   GNU General Public License for more details.
 * |--
 * |--   You should have received a copy of the GNU General Public License
 * |--   along with this program.  If not, see <https://www.gnu.org/licenses/>.
 * |--
 * |-- Platform   : STM32 NUCLEO-WL55JC1
 * |-- Standard   : ISO C11 + GNU extensions
 * |#----------------------------------------------------------------------------#
 * |-- Description: Library to interact with Sensor Hub v3,
 * |                i.e., {en/dis}able ports - interact with connected sensors
 * |#----------------------------------------------------------------------------#
 * |-- Copyright (c) 2022
 * |#----------------------------------------------------------------------------#
 * |-- Revisions  :
 * |-- Date        Version  Author  Description
 * |-- 2022-10-14  1.0              Created
 * |--                              Updated
 * \#-----------------------------------------------------------------------------\
 * *******************************************************************************/


/***** Includes   ******/
#include "shub_v3_0.h"
#include "main.h" //Error_Handler()
#include "string.h"
#if defined(STM32WL55xx)
#include "stm32wlxx_hal.h"
#else
#error "Board not suppoerted! "
#endif

/* *** Comment ***
 * ADC READ pin (PA13) interferes SWDIO
 * Disable debug (ugly solution)
 * */

/* *** Comment ***
 * prob lines were disabled is ID2 and ID3 interferes with PROB3 and PROB2 respectively
 * PROB1: PB12
 * PROB2: PB13
 * PROB3: PB14
 * PROB4: PB10
 * */

/* *** Comment ***
 * SW1_IN1 interferes with FE_CTRL1 (PC4)
 * Do not init or deinit pin here, as radio BSB does so
 * as output push-pull no pull that fits our use case
 * */

/* *** Comment ***
 * SW1_IN2 interferes with B1 (PA0)
 * move B1 to PC13 by removing SB13 and soldering SB15
 * OR
 * Do not use B1
 * */

/* *** Comment ***
 * AI_INT1 interferes with B3 (PC6)
 * disable B3 by removing R23
 * OR
 * do not use B3
 * */

/***** Defines    ******/

/*
 *
 * The NUCLEO-WL55JC1 board is configured to use the following GPIO pins that are required to operate the Sensor HUB v3:
 *
 * Select a sensor port (audio jack) for powering and reading the sensor:
 *
 *    WL55JC1 ---> Sensor HUB
 *    ----------------------------------
 *    PB1        --->  SW2_3_IN1
 *    PB2        --->  SW2_3_IN2
 *
 * Enable ADC read:
 *
 *    WL55JC1 ---> Sensor HUB
 *    ----------------------------------
 *    PC4        --->  SW1_IN1
 *    PA0        --->  SW1_IN2
 *
 *
 * Receive data from UART (Audio jack Sx ports) (USART1_RX)
 *
 *    WL55JC1 ---> Sensor HUB
 *    ----------------------------------
 *    PA10        --->  USART1 RX
 *
 * Enable powering the sensor ports with 4V:
 *
 *    WL55JC1 ---> Sensor HUB
 *    ----------------------------------
 *    PA6       --->  LD0_4V_EN
 *
 * Enable powering I2C MLC bus
 *
 *    WL55JC1 ---> Sensor HUB
 *    ----------------------------------
 *    PA7       --->  EN_MLC_POW
 *
 * Enable powering I2C bus
 *
 *    WL55JC1 ---> Sensor HUB
 *    ----------------------------------
 *    PA5       --->  EN_I2C_SENS_POW
 *
 * Communicate over I2C (2)
 *
 *    WL55JC1 ---> Sensor HUB
 *    ----------------------------------
 *    PA12      --->  I2C_SCL
 *    PA11      --->  I2C_SDA
 *
 * Detect a plugged sensor (insertion detection)
 *
 *    WL55JC1 ---> Sensor HUB
 *    ----------------------------------
 *    PB4       --->  Insertion detection of sensor port 1
 *    PB14      --->  Insertion detection of sensor port 2
 *    PB13      --->  Insertion detection of sensor port 3
 *
 */

/* IC2 pins */
#define SHUB_I2C_SDA             GPIO_PIN_11
#define SHUB_I2C_SDA_Port        GPIOA
#define SHUB_I2C_SCL             GPIO_PIN_12
#define SHUB_I2C_SCL_Port        GPIOA

/* ADC Read enable Pins */
//XXX: PC4 is also FE_CTRL1 pin (RF front-end configuration);
//     read before updating and restore value if required.
#define SW1_IN1_Pin              GPIO_PIN_4
#define SW1_IN1_GPIO_Port        GPIOC
//XXX: PA0 is also B1
#define SW1_IN2_Pin              GPIO_PIN_0
#define SW1_IN2_GPIO_Port        GPIOA

/* Sensors 1-3 enable (power/data) pins */
#define SW2_3_IN1_Pin            GPIO_PIN_1
#define SW2_3_IN1_GPIO_Port      GPIOB
#define SW2_3_IN2_Pin            GPIO_PIN_2
#define SW2_3_IN2_GPIO_Port      GPIOB

/* Sensors 1-3 insertion detection pins */
#define INS_DET1_Pin             GPIO_PIN_4
#define INS_DET1_GPIO_Port       GPIOB
//XXX: PB14 is also PROB3, breaks LoRaWAN debug
#define INS_DET2_Pin             GPIO_PIN_14
#define INS_DET2_GPIO_Port       GPIOB
//XXX: PB13 is also PROB2, breaks LoRaWAN debug
#define INS_DET3_Pin             GPIO_PIN_13
#define INS_DET3_GPIO_Port       GPIOB

/* I2C power enable pin */
#define I2C_POW_ENA_Pin          GPIO_PIN_5
#define I2C_POW_ENA_GPIO_Port    GPIOA

/* I2C power enable pin */
#define MLC_POW_ENA_Pin          GPIO_PIN_7
#define MLC_POW_ENA_GPIO_Port    GPIOA

/* I2C bus pins */
#define I2C_SCL_Pin              GPIO_PIN_12
#define I2C_SCL_GPIO_Port        GPIOA
#define I2C_SDA_Pin              GPIO_PIN_11
#define I2C_SDA_GPIO_Port        GPIOA

#define LD0_4V_EN_Pin            GPIO_PIN_6
#define LD0_4V_EN_GPIO_Port      GPIOA

/***** Priv Func  ******/
static void io_init( void );
//static void io_deinit( void );

/***** Extern Var  ******/
#if ( SHUB_INIT_I2C == 1U )
extern I2C_HandleTypeDef hi2c2;
#endif // ( I2C_ENABLED )

static uint8_t measurement_active = 0;
static GPIO_PinState fe_ctrl1_latch;
/***** Global Variables  ******/


/***** Global Functions  ******/
void shub_power_i2c_on()
{
  __HAL_RCC_GPIOA_CLK_ENABLE();
  HAL_GPIO_WritePin(I2C_POW_ENA_GPIO_Port, I2C_POW_ENA_Pin, GPIO_PIN_SET);
  /* Give some space for the switch to stabilize */
  HAL_Delay(5);
}

void shub_power_i2c_off()
{
  __HAL_RCC_GPIOA_CLK_ENABLE();
  HAL_GPIO_WritePin(I2C_POW_ENA_GPIO_Port, I2C_POW_ENA_Pin, GPIO_PIN_RESET);
}

void shub_power_i2c_mlc_on()
{
  __HAL_RCC_GPIOA_CLK_ENABLE();
  HAL_GPIO_WritePin(MLC_POW_ENA_GPIO_Port, MLC_POW_ENA_Pin, GPIO_PIN_SET);
  /* Give some space for the switch to stabilize */
  HAL_Delay(5);
}

void shub_power_i2c_mlc_off()
{
  __HAL_RCC_GPIOA_CLK_ENABLE();
  HAL_GPIO_WritePin(MLC_POW_ENA_GPIO_Port, MLC_POW_ENA_Pin, GPIO_PIN_RESET);
}

void shub_init(void)
{
#if ( SHUB_INIT_I2C )
  GPIO_InitTypeDef GPIO_InitStruct_i2c = {0};

  if (hi2c2.Instance != I2C2) {
    hi2c2.Instance = I2C2;
    hi2c2.Init.Timing = 0x20000209;
    hi2c2.Init.OwnAddress1 = 0;
    hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
    hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
    hi2c2.Init.OwnAddress2 = 0;
    hi2c2.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
    hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
    hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_ENABLE;
    if (HAL_I2C_Init(&hi2c2) != HAL_OK) {
      Error_Handler();
    }
    /** Configure Analog filter */
    if (HAL_I2CEx_ConfigAnalogFilter(&hi2c2, I2C_ANALOGFILTER_ENABLE) != HAL_OK) {
      Error_Handler();
    }
    /** Configure Digital filter */
    if (HAL_I2CEx_ConfigDigitalFilter(&hi2c2, 0) != HAL_OK) {
      Error_Handler();
    }
    /** I2C Fast mode Plus enable */
    HAL_I2CEx_EnableFastModePlus(I2C_FASTMODEPLUS_I2C2);
  }
#endif // ( SHUB_INIT_I2C )

  // initialize GPIOs (switches 'n' detection pins)
  io_init();
}

/***** Priv Func  ******/
static void io_init( void )
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  //Initialize GPIO ports
  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SW2_3_IN1_Pin|SW2_3_IN2_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA, LD0_4V_EN_Pin|SW1_IN2_Pin|I2C_POW_ENA_Pin|MLC_POW_ENA_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOC, SW1_IN1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO B pins */
  GPIO_InitStruct.Pin = SW2_3_IN1_Pin|SW2_3_IN2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* Insertion Detection PINS initialization moved to check port function
   * to overcome conflicts with USART2 TX (PA2)
   */

  /*Configure GPIO A pins */
  GPIO_InitStruct.Pin = LD0_4V_EN_Pin|SW1_IN2_Pin|I2C_POW_ENA_Pin|MLC_POW_ENA_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO C pins */
  GPIO_InitStruct.Pin = SW1_IN1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(SW1_IN1_GPIO_Port, &GPIO_InitStruct);
}

#if ( SHUB_INIT_I2C == 1U )
/**
* @brief I2C MSP Initialization
* This function configures the hardware resources used in this example
* @param hi2c: I2C handle pointer
* @retval None
*/
void HAL_I2C_MspInit(I2C_HandleTypeDef* hi2c)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	if (hi2c->Instance == I2C2) {
		__HAL_RCC_GPIOA_CLK_ENABLE();
	    /**I2C2 GPIO Configuration
	    PA11     ------> I2C2_SDA
	    PA12     ------> I2C2_SCL
	    */
	    GPIO_InitStruct.Pin = SHUB_I2C_SDA|SHUB_I2C_SCL;
	    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
	    GPIO_InitStruct.Pull = GPIO_NOPULL;
	    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	    GPIO_InitStruct.Alternate = GPIO_AF4_I2C2;
	    HAL_GPIO_Init(SHUB_I2C_SDA_Port, &GPIO_InitStruct);

		/* Peripheral clock enable */
		__HAL_RCC_I2C2_CLK_ENABLE();
	}
}

/**
* @brief I2C MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param hi2c: I2C handle pointer
* @retval None
*/
void HAL_I2C_MspDeInit(I2C_HandleTypeDef* hi2c)
{
  if(hi2c->Instance==I2C2)
  {
    /* Peripheral clock disable */
    __HAL_RCC_I2C2_CLK_DISABLE();

    /**I2C2 GPIO Configuration
    PA11     ------> I2C2_SDA
    PA12     ------> I2C2_SCL
    */
    HAL_GPIO_DeInit(SHUB_I2C_SDA_Port, SHUB_I2C_SDA);

    HAL_GPIO_DeInit(SHUB_I2C_SCL_Port, SHUB_I2C_SCL);

    hi2c->Instance = NULL;
  }

}
#endif // ( SHUB_INIT_I2C == 1U )
