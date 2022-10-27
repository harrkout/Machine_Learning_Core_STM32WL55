################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/STM32WLxx_Nucleo/stm32wlxx_nucleo.c 

OBJS += \
./Drivers/BSP/STM32WLxx_Nucleo/stm32wlxx_nucleo.o 

C_DEPS += \
./Drivers/BSP/STM32WLxx_Nucleo/stm32wlxx_nucleo.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32WLxx_Nucleo/%.o Drivers/BSP/STM32WLxx_Nucleo/%.su: ../Drivers/BSP/STM32WLxx_Nucleo/%.c Drivers/BSP/STM32WLxx_Nucleo/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DCORE_CM4 -DUSE_HAL_DRIVER -DSTM32WL55xx -c -I../Core/Inc -I../Drivers/STM32WLxx_HAL_Driver/Inc -I../Drivers/STM32WLxx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../Drivers/CMSIS/Include -I../MEMS/Target -I../Middlewares/ST/STM32_MotionFX_Library/Inc -I../Drivers/BSP/Components/Common -I../Middlewares/ST/STM32_MotionAC_Library/Inc -I../Drivers/BSP/Components/lsm6dsox -I../MEMS/App -I../Drivers/BSP/STM32WLxx_Nucleo -I../Middlewares/ST/STM32_MotionGR_Library/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-STM32WLxx_Nucleo

clean-Drivers-2f-BSP-2f-STM32WLxx_Nucleo:
	-$(RM) ./Drivers/BSP/STM32WLxx_Nucleo/stm32wlxx_nucleo.d ./Drivers/BSP/STM32WLxx_Nucleo/stm32wlxx_nucleo.o ./Drivers/BSP/STM32WLxx_Nucleo/stm32wlxx_nucleo.su

.PHONY: clean-Drivers-2f-BSP-2f-STM32WLxx_Nucleo

