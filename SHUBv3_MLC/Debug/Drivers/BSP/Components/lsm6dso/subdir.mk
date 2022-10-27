################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Components/lsm6dso/lsm6dso.c \
../Drivers/BSP/Components/lsm6dso/lsm6dso_reg.c 

OBJS += \
./Drivers/BSP/Components/lsm6dso/lsm6dso.o \
./Drivers/BSP/Components/lsm6dso/lsm6dso_reg.o 

C_DEPS += \
./Drivers/BSP/Components/lsm6dso/lsm6dso.d \
./Drivers/BSP/Components/lsm6dso/lsm6dso_reg.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/lsm6dso/%.o Drivers/BSP/Components/lsm6dso/%.su: ../Drivers/BSP/Components/lsm6dso/%.c Drivers/BSP/Components/lsm6dso/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DCORE_CM4 -DUSE_HAL_DRIVER -DSTM32WL55xx -c -I../Core/Inc -I../Drivers/STM32WLxx_HAL_Driver/Inc -I../Drivers/STM32WLxx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../Drivers/CMSIS/Include -I../MEMS/App -I../MEMS/Target -I../Drivers/BSP/STM32WLxx_Nucleo -I../Middlewares/ST/STM32_MotionFX_Library/Inc -I../Drivers/BSP/Components/Common -I../Middlewares/ST/STM32_MotionAC_Library/Inc -I../Drivers/BSP/Components/lsm6dsox -I../Drivers/BSP/Components/lsm6dso -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components-2f-lsm6dso

clean-Drivers-2f-BSP-2f-Components-2f-lsm6dso:
	-$(RM) ./Drivers/BSP/Components/lsm6dso/lsm6dso.d ./Drivers/BSP/Components/lsm6dso/lsm6dso.o ./Drivers/BSP/Components/lsm6dso/lsm6dso.su ./Drivers/BSP/Components/lsm6dso/lsm6dso_reg.d ./Drivers/BSP/Components/lsm6dso/lsm6dso_reg.o ./Drivers/BSP/Components/lsm6dso/lsm6dso_reg.su

.PHONY: clean-Drivers-2f-BSP-2f-Components-2f-lsm6dso

