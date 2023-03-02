################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/libleguan/source/peripherals/external/sensors/icm42605.c \
../lib/libleguan/source/peripherals/external/sensors/lps22bh.c \
../lib/libleguan/source/peripherals/external/sensors/sht40.c \
../lib/libleguan/source/peripherals/external/sensors/tcs34725.c 

OBJS += \
./lib/libleguan/source/peripherals/external/sensors/icm42605.o \
./lib/libleguan/source/peripherals/external/sensors/lps22bh.o \
./lib/libleguan/source/peripherals/external/sensors/sht40.o \
./lib/libleguan/source/peripherals/external/sensors/tcs34725.o 

C_DEPS += \
./lib/libleguan/source/peripherals/external/sensors/icm42605.d \
./lib/libleguan/source/peripherals/external/sensors/lps22bh.d \
./lib/libleguan/source/peripherals/external/sensors/sht40.d \
./lib/libleguan/source/peripherals/external/sensors/tcs34725.d 


# Each subdirectory must supply rules for building sources it contributes
lib/libleguan/source/peripherals/external/sensors/%.o lib/libleguan/source/peripherals/external/sensors/%.su: ../lib/libleguan/source/peripherals/external/sensors/%.c lib/libleguan/source/peripherals/external/sensors/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu17 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../lib/hal/Core/Inc -I../lib/libleguan/include -I../lib/hal/Drivers/STM32H7xx_HAL_Driver/Inc -I../lib/hal/Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../lib/hal/Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../lib/hal/Drivers/CMSIS/Include -I../lib/hal/FATFS/Target -I../lib/hal/FATFS/App -I../lib/hal/USB_DEVICE/App -I../lib/hal/USB_DEVICE/Target -I../lib/hal/Middlewares/Third_Party/FatFs/src -I../lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../lib/hal/Middlewares/ST/STM32_USB_Device_Library/Class/CustomHID/Inc -I../include -O0 -ffunction-sections -fdata-sections -Wall -Werror -mfp16-format=ieee -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lib-2f-libleguan-2f-source-2f-peripherals-2f-external-2f-sensors

clean-lib-2f-libleguan-2f-source-2f-peripherals-2f-external-2f-sensors:
	-$(RM) ./lib/libleguan/source/peripherals/external/sensors/icm42605.d ./lib/libleguan/source/peripherals/external/sensors/icm42605.o ./lib/libleguan/source/peripherals/external/sensors/icm42605.su ./lib/libleguan/source/peripherals/external/sensors/lps22bh.d ./lib/libleguan/source/peripherals/external/sensors/lps22bh.o ./lib/libleguan/source/peripherals/external/sensors/lps22bh.su ./lib/libleguan/source/peripherals/external/sensors/sht40.d ./lib/libleguan/source/peripherals/external/sensors/sht40.o ./lib/libleguan/source/peripherals/external/sensors/sht40.su ./lib/libleguan/source/peripherals/external/sensors/tcs34725.d ./lib/libleguan/source/peripherals/external/sensors/tcs34725.o ./lib/libleguan/source/peripherals/external/sensors/tcs34725.su

.PHONY: clean-lib-2f-libleguan-2f-source-2f-peripherals-2f-external-2f-sensors

