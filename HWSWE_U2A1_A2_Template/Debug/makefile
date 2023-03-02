################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include source/subdir.mk
-include lib/libleguan/source/peripherals/internal/subdir.mk
-include lib/libleguan/source/peripherals/external/sensors/subdir.mk
-include lib/libleguan/source/peripherals/external/subdir.mk
-include lib/libleguan/source/common/subdir.mk
-include lib/libleguan/source/subdir.mk
-include lib/hal/USB_DEVICE/Target/subdir.mk
-include lib/hal/USB_DEVICE/App/subdir.mk
-include lib/hal/Middlewares/Third_Party/FatFs/src/option/subdir.mk
-include lib/hal/Middlewares/Third_Party/FatFs/src/subdir.mk
-include lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Src/subdir.mk
-include lib/hal/Middlewares/ST/STM32_USB_Device_Library/Class/CustomHID/Src/subdir.mk
-include lib/hal/FATFS/Target/subdir.mk
-include lib/hal/FATFS/App/subdir.mk
-include lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/subdir.mk
-include lib/hal/Core/Startup/subdir.mk
-include lib/hal/Core/Src/subdir.mk
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


BUILD_ARTIFACT_NAME := HWSWE_U2A1_A2_Template
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
HWSWE_U2A1_A2_Template.elf \

MAP_FILES += \
HWSWE_U2A1_A2_Template.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
HWSWE_U2A1_A2_Template.list \


# All Target
all: main-build

# Main-build Target
main-build: HWSWE_U2A1_A2_Template.elf secondary-outputs

# Tool invocations
HWSWE_U2A1_A2_Template.elf HWSWE_U2A1_A2_Template.map: $(OBJS) $(USER_OBJS) C:\Users\Tim\Documents\Studium\4.Semester\HWSW\HWSWE_U2A1_A2_Template\STM32H743ZITX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "HWSWE_U2A1_A2_Template.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"C:\Users\Tim\Documents\Studium\4.Semester\HWSW\HWSWE_U2A1_A2_Template\STM32H743ZITX_FLASH.ld" --specs=nosys.specs -Wl,-Map="HWSWE_U2A1_A2_Template.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -u _printf_float -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

HWSWE_U2A1_A2_Template.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "HWSWE_U2A1_A2_Template.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) HWSWE_U2A1_A2_Template.elf HWSWE_U2A1_A2_Template.list HWSWE_U2A1_A2_Template.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
