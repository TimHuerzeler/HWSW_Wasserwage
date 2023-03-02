################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/libleguan/source/common/core.c \
../lib/libleguan/source/common/fpu.c \
../lib/libleguan/source/common/logger.c \
../lib/libleguan/source/common/math.c 

OBJS += \
./lib/libleguan/source/common/core.o \
./lib/libleguan/source/common/fpu.o \
./lib/libleguan/source/common/logger.o \
./lib/libleguan/source/common/math.o 

C_DEPS += \
./lib/libleguan/source/common/core.d \
./lib/libleguan/source/common/fpu.d \
./lib/libleguan/source/common/logger.d \
./lib/libleguan/source/common/math.d 


# Each subdirectory must supply rules for building sources it contributes
lib/libleguan/source/common/%.o: ../lib/libleguan/source/common/%.c lib/libleguan/source/common/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu17 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../lib/hal/Core/Inc -I../lib/libleguan/include -I../lib/hal/Drivers/STM32H7xx_HAL_Driver/Inc -I../lib/hal/Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../lib/hal/Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../lib/hal/Drivers/CMSIS/Include -I../lib/hal/FATFS/Target -I../lib/hal/FATFS/App -I../lib/hal/USB_DEVICE/App -I../lib/hal/USB_DEVICE/Target -I../lib/hal/Middlewares/Third_Party/FatFs/src -I../lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../lib/hal/Middlewares/ST/STM32_USB_Device_Library/Class/CustomHID/Inc -I../include -O0 -ffunction-sections -fdata-sections -Wall -Werror -mfp16-format=ieee -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lib-2f-libleguan-2f-source-2f-common

clean-lib-2f-libleguan-2f-source-2f-common:
	-$(RM) ./lib/libleguan/source/common/core.d ./lib/libleguan/source/common/core.o ./lib/libleguan/source/common/fpu.d ./lib/libleguan/source/common/fpu.o ./lib/libleguan/source/common/logger.d ./lib/libleguan/source/common/logger.o ./lib/libleguan/source/common/math.d ./lib/libleguan/source/common/math.o

.PHONY: clean-lib-2f-libleguan-2f-source-2f-common

