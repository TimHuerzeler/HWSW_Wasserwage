################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/libleguan/source/peripherals/internal/adc.c \
../lib/libleguan/source/peripherals/internal/dac.c \
../lib/libleguan/source/peripherals/internal/gpio.c \
../lib/libleguan/source/peripherals/internal/i2c.c \
../lib/libleguan/source/peripherals/internal/serial.c \
../lib/libleguan/source/peripherals/internal/spi.c 

OBJS += \
./lib/libleguan/source/peripherals/internal/adc.o \
./lib/libleguan/source/peripherals/internal/dac.o \
./lib/libleguan/source/peripherals/internal/gpio.o \
./lib/libleguan/source/peripherals/internal/i2c.o \
./lib/libleguan/source/peripherals/internal/serial.o \
./lib/libleguan/source/peripherals/internal/spi.o 

C_DEPS += \
./lib/libleguan/source/peripherals/internal/adc.d \
./lib/libleguan/source/peripherals/internal/dac.d \
./lib/libleguan/source/peripherals/internal/gpio.d \
./lib/libleguan/source/peripherals/internal/i2c.d \
./lib/libleguan/source/peripherals/internal/serial.d \
./lib/libleguan/source/peripherals/internal/spi.d 


# Each subdirectory must supply rules for building sources it contributes
lib/libleguan/source/peripherals/internal/%.o lib/libleguan/source/peripherals/internal/%.su lib/libleguan/source/peripherals/internal/%.cyclo: ../lib/libleguan/source/peripherals/internal/%.c lib/libleguan/source/peripherals/internal/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu17 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../lib/hal/Core/Inc -I../lib/libleguan/include -I../lib/hal/Drivers/STM32H7xx_HAL_Driver/Inc -I../lib/hal/Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../lib/hal/Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../lib/hal/Drivers/CMSIS/Include -I../lib/hal/FATFS/Target -I../lib/hal/FATFS/App -I../lib/hal/USB_DEVICE/App -I../lib/hal/USB_DEVICE/Target -I../lib/hal/Middlewares/Third_Party/FatFs/src -I../lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../lib/hal/Middlewares/ST/STM32_USB_Device_Library/Class/CustomHID/Inc -I../include -O0 -ffunction-sections -fdata-sections -Wall -Werror -mfp16-format=ieee -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lib-2f-libleguan-2f-source-2f-peripherals-2f-internal

clean-lib-2f-libleguan-2f-source-2f-peripherals-2f-internal:
	-$(RM) ./lib/libleguan/source/peripherals/internal/adc.cyclo ./lib/libleguan/source/peripherals/internal/adc.d ./lib/libleguan/source/peripherals/internal/adc.o ./lib/libleguan/source/peripherals/internal/adc.su ./lib/libleguan/source/peripherals/internal/dac.cyclo ./lib/libleguan/source/peripherals/internal/dac.d ./lib/libleguan/source/peripherals/internal/dac.o ./lib/libleguan/source/peripherals/internal/dac.su ./lib/libleguan/source/peripherals/internal/gpio.cyclo ./lib/libleguan/source/peripherals/internal/gpio.d ./lib/libleguan/source/peripherals/internal/gpio.o ./lib/libleguan/source/peripherals/internal/gpio.su ./lib/libleguan/source/peripherals/internal/i2c.cyclo ./lib/libleguan/source/peripherals/internal/i2c.d ./lib/libleguan/source/peripherals/internal/i2c.o ./lib/libleguan/source/peripherals/internal/i2c.su ./lib/libleguan/source/peripherals/internal/serial.cyclo ./lib/libleguan/source/peripherals/internal/serial.d ./lib/libleguan/source/peripherals/internal/serial.o ./lib/libleguan/source/peripherals/internal/serial.su ./lib/libleguan/source/peripherals/internal/spi.cyclo ./lib/libleguan/source/peripherals/internal/spi.d ./lib/libleguan/source/peripherals/internal/spi.o ./lib/libleguan/source/peripherals/internal/spi.su

.PHONY: clean-lib-2f-libleguan-2f-source-2f-peripherals-2f-internal

