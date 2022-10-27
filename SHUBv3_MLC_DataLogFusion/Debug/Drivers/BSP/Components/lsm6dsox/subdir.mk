################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Components/lsm6dsox/lsm6dsox.c \
../Drivers/BSP/Components/lsm6dsox/lsm6dsox_reg.c 

OBJS += \
./Drivers/BSP/Components/lsm6dsox/lsm6dsox.o \
./Drivers/BSP/Components/lsm6dsox/lsm6dsox_reg.o 

C_DEPS += \
./Drivers/BSP/Components/lsm6dsox/lsm6dsox.d \
./Drivers/BSP/Components/lsm6dsox/lsm6dsox_reg.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/lsm6dsox/%.o Drivers/BSP/Components/lsm6dsox/%.su: ../Drivers/BSP/Components/lsm6dsox/%.c Drivers/BSP/Components/lsm6dsox/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DCORE_CM4 -DUSE_HAL_DRIVER -DSTM32WL55xx -c -I../MEMS/App -I../MEMS/Target -I../Core/Inc -I../Drivers/BSP/STM32WLxx_Nucleo -I../Drivers/STM32WLxx_HAL_Driver/Inc -I../Drivers/STM32WLxx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/lsm6dsox -I../Middlewares/ST/STM32_MotionFX_Library/Inc -I../Drivers/BSP/Components/Common -I../Middlewares/ST/STM32_MotionAC_Library/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components-2f-lsm6dsox

clean-Drivers-2f-BSP-2f-Components-2f-lsm6dsox:
	-$(RM) ./Drivers/BSP/Components/lsm6dsox/lsm6dsox.d ./Drivers/BSP/Components/lsm6dsox/lsm6dsox.o ./Drivers/BSP/Components/lsm6dsox/lsm6dsox.su ./Drivers/BSP/Components/lsm6dsox/lsm6dsox_reg.d ./Drivers/BSP/Components/lsm6dsox/lsm6dsox_reg.o ./Drivers/BSP/Components/lsm6dsox/lsm6dsox_reg.su

.PHONY: clean-Drivers-2f-BSP-2f-Components-2f-lsm6dsox

