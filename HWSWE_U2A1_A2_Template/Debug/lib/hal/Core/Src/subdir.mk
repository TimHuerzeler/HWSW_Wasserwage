################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/hal/Core/Src/adc.c \
../lib/hal/Core/Src/cube.c \
../lib/hal/Core/Src/dac.c \
../lib/hal/Core/Src/dma2d.c \
../lib/hal/Core/Src/fdcan.c \
../lib/hal/Core/Src/fmc.c \
../lib/hal/Core/Src/gpio.c \
../lib/hal/Core/Src/i2c.c \
../lib/hal/Core/Src/i2s.c \
../lib/hal/Core/Src/main.c \
../lib/hal/Core/Src/sdmmc.c \
../lib/hal/Core/Src/spi.c \
../lib/hal/Core/Src/stm32h7xx_hal_msp.c \
../lib/hal/Core/Src/stm32h7xx_it.c \
../lib/hal/Core/Src/syscalls.c \
../lib/hal/Core/Src/sysmem.c \
../lib/hal/Core/Src/system_stm32h7xx.c \
../lib/hal/Core/Src/usart.c 

OBJS += \
./lib/hal/Core/Src/adc.o \
./lib/hal/Core/Src/cube.o \
./lib/hal/Core/Src/dac.o \
./lib/hal/Core/Src/dma2d.o \
./lib/hal/Core/Src/fdcan.o \
./lib/hal/Core/Src/fmc.o \
./lib/hal/Core/Src/gpio.o \
./lib/hal/Core/Src/i2c.o \
./lib/hal/Core/Src/i2s.o \
./lib/hal/Core/Src/main.o \
./lib/hal/Core/Src/sdmmc.o \
./lib/hal/Core/Src/spi.o \
./lib/hal/Core/Src/stm32h7xx_hal_msp.o \
./lib/hal/Core/Src/stm32h7xx_it.o \
./lib/hal/Core/Src/syscalls.o \
./lib/hal/Core/Src/sysmem.o \
./lib/hal/Core/Src/system_stm32h7xx.o \
./lib/hal/Core/Src/usart.o 

C_DEPS += \
./lib/hal/Core/Src/adc.d \
./lib/hal/Core/Src/cube.d \
./lib/hal/Core/Src/dac.d \
./lib/hal/Core/Src/dma2d.d \
./lib/hal/Core/Src/fdcan.d \
./lib/hal/Core/Src/fmc.d \
./lib/hal/Core/Src/gpio.d \
./lib/hal/Core/Src/i2c.d \
./lib/hal/Core/Src/i2s.d \
./lib/hal/Core/Src/main.d \
./lib/hal/Core/Src/sdmmc.d \
./lib/hal/Core/Src/spi.d \
./lib/hal/Core/Src/stm32h7xx_hal_msp.d \
./lib/hal/Core/Src/stm32h7xx_it.d \
./lib/hal/Core/Src/syscalls.d \
./lib/hal/Core/Src/sysmem.d \
./lib/hal/Core/Src/system_stm32h7xx.d \
./lib/hal/Core/Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
lib/hal/Core/Src/%.o lib/hal/Core/Src/%.su: ../lib/hal/Core/Src/%.c lib/hal/Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu17 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../lib/hal/Core/Inc -I../lib/libleguan/include -I../lib/hal/Drivers/STM32H7xx_HAL_Driver/Inc -I../lib/hal/Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../lib/hal/Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../lib/hal/Drivers/CMSIS/Include -I../lib/hal/FATFS/Target -I../lib/hal/FATFS/App -I../lib/hal/USB_DEVICE/App -I../lib/hal/USB_DEVICE/Target -I../lib/hal/Middlewares/Third_Party/FatFs/src -I../lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../lib/hal/Middlewares/ST/STM32_USB_Device_Library/Class/CustomHID/Inc -I../include -O0 -ffunction-sections -fdata-sections -Wall -Werror -mfp16-format=ieee -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lib-2f-hal-2f-Core-2f-Src

clean-lib-2f-hal-2f-Core-2f-Src:
	-$(RM) ./lib/hal/Core/Src/adc.d ./lib/hal/Core/Src/adc.o ./lib/hal/Core/Src/adc.su ./lib/hal/Core/Src/cube.d ./lib/hal/Core/Src/cube.o ./lib/hal/Core/Src/cube.su ./lib/hal/Core/Src/dac.d ./lib/hal/Core/Src/dac.o ./lib/hal/Core/Src/dac.su ./lib/hal/Core/Src/dma2d.d ./lib/hal/Core/Src/dma2d.o ./lib/hal/Core/Src/dma2d.su ./lib/hal/Core/Src/fdcan.d ./lib/hal/Core/Src/fdcan.o ./lib/hal/Core/Src/fdcan.su ./lib/hal/Core/Src/fmc.d ./lib/hal/Core/Src/fmc.o ./lib/hal/Core/Src/fmc.su ./lib/hal/Core/Src/gpio.d ./lib/hal/Core/Src/gpio.o ./lib/hal/Core/Src/gpio.su ./lib/hal/Core/Src/i2c.d ./lib/hal/Core/Src/i2c.o ./lib/hal/Core/Src/i2c.su ./lib/hal/Core/Src/i2s.d ./lib/hal/Core/Src/i2s.o ./lib/hal/Core/Src/i2s.su ./lib/hal/Core/Src/main.d ./lib/hal/Core/Src/main.o ./lib/hal/Core/Src/main.su ./lib/hal/Core/Src/sdmmc.d ./lib/hal/Core/Src/sdmmc.o ./lib/hal/Core/Src/sdmmc.su ./lib/hal/Core/Src/spi.d ./lib/hal/Core/Src/spi.o ./lib/hal/Core/Src/spi.su ./lib/hal/Core/Src/stm32h7xx_hal_msp.d ./lib/hal/Core/Src/stm32h7xx_hal_msp.o ./lib/hal/Core/Src/stm32h7xx_hal_msp.su ./lib/hal/Core/Src/stm32h7xx_it.d ./lib/hal/Core/Src/stm32h7xx_it.o ./lib/hal/Core/Src/stm32h7xx_it.su ./lib/hal/Core/Src/syscalls.d ./lib/hal/Core/Src/syscalls.o ./lib/hal/Core/Src/syscalls.su ./lib/hal/Core/Src/sysmem.d ./lib/hal/Core/Src/sysmem.o ./lib/hal/Core/Src/sysmem.su ./lib/hal/Core/Src/system_stm32h7xx.d ./lib/hal/Core/Src/system_stm32h7xx.o ./lib/hal/Core/Src/system_stm32h7xx.su ./lib/hal/Core/Src/usart.d ./lib/hal/Core/Src/usart.o ./lib/hal/Core/Src/usart.su

.PHONY: clean-lib-2f-hal-2f-Core-2f-Src

