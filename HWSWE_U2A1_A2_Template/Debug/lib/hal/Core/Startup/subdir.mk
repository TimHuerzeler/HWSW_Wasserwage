################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../lib/hal/Core/Startup/startup_stm32h743zitx.s 

OBJS += \
./lib/hal/Core/Startup/startup_stm32h743zitx.o 

S_DEPS += \
./lib/hal/Core/Startup/startup_stm32h743zitx.d 


# Each subdirectory must supply rules for building sources it contributes
lib/hal/Core/Startup/%.o: ../lib/hal/Core/Startup/%.s lib/hal/Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -mfp16-format=ieee -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-lib-2f-hal-2f-Core-2f-Startup

clean-lib-2f-hal-2f-Core-2f-Startup:
	-$(RM) ./lib/hal/Core/Startup/startup_stm32h743zitx.d ./lib/hal/Core/Startup/startup_stm32h743zitx.o

.PHONY: clean-lib-2f-hal-2f-Core-2f-Startup

