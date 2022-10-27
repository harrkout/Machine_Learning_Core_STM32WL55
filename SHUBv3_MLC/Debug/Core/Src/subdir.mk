################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lsm6dsox_mlc.c \
../Core/Src/main.c \
../Core/Src/shub_v3_0.c \
../Core/Src/stm32wlxx_hal_msp.c \
../Core/Src/stm32wlxx_it.c \
../Core/Src/stm32wlxx_nucleo_bus.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32wlxx.c 

OBJS += \
./Core/Src/lsm6dsox_mlc.o \
./Core/Src/main.o \
./Core/Src/shub_v3_0.o \
./Core/Src/stm32wlxx_hal_msp.o \
./Core/Src/stm32wlxx_it.o \
./Core/Src/stm32wlxx_nucleo_bus.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32wlxx.o 

C_DEPS += \
./Core/Src/lsm6dsox_mlc.d \
./Core/Src/main.d \
./Core/Src/shub_v3_0.d \
./Core/Src/stm32wlxx_hal_msp.d \
./Core/Src/stm32wlxx_it.d \
./Core/Src/stm32wlxx_nucleo_bus.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32wlxx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DCORE_CM4 -DUSE_HAL_DRIVER -DSTM32WL55xx -c -I../Core/Inc -I../Drivers/STM32WLxx_HAL_Driver/Inc -I../Drivers/STM32WLxx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../Drivers/CMSIS/Include -I../MEMS/Target -I../Middlewares/ST/STM32_MotionFX_Library/Inc -I../Drivers/BSP/Components/Common -I../Middlewares/ST/STM32_MotionAC_Library/Inc -I../Drivers/BSP/Components/lsm6dsox -I../MEMS/App -I../Drivers/BSP/STM32WLxx_Nucleo -I../Middlewares/ST/STM32_MotionGR_Library/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/lsm6dsox_mlc.d ./Core/Src/lsm6dsox_mlc.o ./Core/Src/lsm6dsox_mlc.su ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/shub_v3_0.d ./Core/Src/shub_v3_0.o ./Core/Src/shub_v3_0.su ./Core/Src/stm32wlxx_hal_msp.d ./Core/Src/stm32wlxx_hal_msp.o ./Core/Src/stm32wlxx_hal_msp.su ./Core/Src/stm32wlxx_it.d ./Core/Src/stm32wlxx_it.o ./Core/Src/stm32wlxx_it.su ./Core/Src/stm32wlxx_nucleo_bus.d ./Core/Src/stm32wlxx_nucleo_bus.o ./Core/Src/stm32wlxx_nucleo_bus.su ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32wlxx.d ./Core/Src/system_stm32wlxx.o ./Core/Src/system_stm32wlxx.su

.PHONY: clean-Core-2f-Src

