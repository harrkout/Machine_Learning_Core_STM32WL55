################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MEMS/Target/custom_motion_sensors.c \
../MEMS/Target/custom_motion_sensors_ex.c 

OBJS += \
./MEMS/Target/custom_motion_sensors.o \
./MEMS/Target/custom_motion_sensors_ex.o 

C_DEPS += \
./MEMS/Target/custom_motion_sensors.d \
./MEMS/Target/custom_motion_sensors_ex.d 


# Each subdirectory must supply rules for building sources it contributes
MEMS/Target/%.o MEMS/Target/%.su: ../MEMS/Target/%.c MEMS/Target/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DCORE_CM4 -DUSE_HAL_DRIVER -DSTM32WL55xx -c -I../Core/Inc -I../Drivers/STM32WLxx_HAL_Driver/Inc -I../Drivers/STM32WLxx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../Drivers/CMSIS/Include -I../MEMS/Target -I../Middlewares/ST/STM32_MotionFX_Library/Inc -I../Drivers/BSP/Components/Common -I../Middlewares/ST/STM32_MotionAC_Library/Inc -I../Drivers/BSP/Components/lsm6dsox -I../MEMS/App -I../Drivers/BSP/STM32WLxx_Nucleo -I../Middlewares/ST/STM32_MotionGR_Library/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MEMS-2f-Target

clean-MEMS-2f-Target:
	-$(RM) ./MEMS/Target/custom_motion_sensors.d ./MEMS/Target/custom_motion_sensors.o ./MEMS/Target/custom_motion_sensors.su ./MEMS/Target/custom_motion_sensors_ex.d ./MEMS/Target/custom_motion_sensors_ex.o ./MEMS/Target/custom_motion_sensors_ex.su

.PHONY: clean-MEMS-2f-Target

