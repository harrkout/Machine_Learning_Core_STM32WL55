################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MEMS/Target/subdir.mk
-include MEMS/App/subdir.mk
-include Drivers/STM32WLxx_HAL_Driver/Src/subdir.mk
-include Drivers/BSP/STM32WLxx_Nucleo/subdir.mk
-include Drivers/BSP/Components/lsm6dsox/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := SHUBv3_MLC
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
SHUBv3_MLC.elf \

MAP_FILES += \
SHUBv3_MLC.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
SHUBv3_MLC.list \


# All Target
all: main-build

# Main-build Target
main-build: SHUBv3_MLC.elf secondary-outputs

# Tool invocations
SHUBv3_MLC.elf SHUBv3_MLC.map: $(OBJS) $(USER_OBJS) C:\Users\harry\Desktop\Stm32MX_AI_ML_Projects\SHUBv3_MLC\STM32WL55JCIX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "SHUBv3_MLC.elf" @"objects.list" $(USER_OBJS) -Wl,--start-group $(LIBS) -Wl,--end-group -mcpu=cortex-m4 -T"C:\Users\harry\Desktop\Stm32MX_AI_ML_Projects\SHUBv3_MLC\STM32WL55JCIX_FLASH.ld" --specs=nosys.specs -Wl,-Map="SHUBv3_MLC.map" -Wl,--gc-sections -static -L../Middlewares/ST/STM32_MotionFX_Library/Lib -L../Middlewares/ST/STM32_MotionAC_Library/Lib -L../Middlewares/ST/STM32_MotionGR_Library/Lib --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

SHUBv3_MLC.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "SHUBv3_MLC.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) SHUBv3_MLC.elf SHUBv3_MLC.list SHUBv3_MLC.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
