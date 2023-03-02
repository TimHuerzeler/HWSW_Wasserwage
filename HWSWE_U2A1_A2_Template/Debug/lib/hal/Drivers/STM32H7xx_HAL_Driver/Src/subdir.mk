################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_adc.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_adc_ex.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_cortex.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dac.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dac_ex.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma2d.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma_ex.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_exti.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_fdcan.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash_ex.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_gpio.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_hsem.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c_ex.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2s.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2s_ex.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_mdma.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pcd.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pcd_ex.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr_ex.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc_ex.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sd.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sd_ex.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sdram.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_spi.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_spi_ex.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sram.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim_ex.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_uart.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_uart_ex.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_delayblock.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_fmc.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_sdmmc.c \
../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_usb.c 

OBJS += \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_adc.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_adc_ex.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_cortex.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dac.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dac_ex.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma2d.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma_ex.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_exti.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_fdcan.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash_ex.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_gpio.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_hsem.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c_ex.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2s.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2s_ex.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_mdma.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pcd.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pcd_ex.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr_ex.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc_ex.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sd.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sd_ex.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sdram.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_spi.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_spi_ex.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sram.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim_ex.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_uart.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_uart_ex.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_delayblock.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_fmc.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_sdmmc.o \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_usb.o 

C_DEPS += \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_adc.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_adc_ex.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_cortex.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dac.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dac_ex.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma2d.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma_ex.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_exti.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_fdcan.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash_ex.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_gpio.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_hsem.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c_ex.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2s.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2s_ex.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_mdma.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pcd.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pcd_ex.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr_ex.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc_ex.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sd.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sd_ex.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sdram.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_spi.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_spi_ex.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sram.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim_ex.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_uart.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_uart_ex.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_delayblock.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_fmc.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_sdmmc.d \
./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_usb.d 


# Each subdirectory must supply rules for building sources it contributes
lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/%.o: ../lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/%.c lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu17 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../lib/hal/Core/Inc -I../lib/libleguan/include -I../lib/hal/Drivers/STM32H7xx_HAL_Driver/Inc -I../lib/hal/Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../lib/hal/Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../lib/hal/Drivers/CMSIS/Include -I../lib/hal/FATFS/Target -I../lib/hal/FATFS/App -I../lib/hal/USB_DEVICE/App -I../lib/hal/USB_DEVICE/Target -I../lib/hal/Middlewares/Third_Party/FatFs/src -I../lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../lib/hal/Middlewares/ST/STM32_USB_Device_Library/Class/CustomHID/Inc -I../include -O0 -ffunction-sections -fdata-sections -Wall -Werror -mfp16-format=ieee -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lib-2f-hal-2f-Drivers-2f-STM32H7xx_HAL_Driver-2f-Src

clean-lib-2f-hal-2f-Drivers-2f-STM32H7xx_HAL_Driver-2f-Src:
	-$(RM) ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_adc.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_adc.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_adc_ex.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_adc_ex.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_cortex.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_cortex.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dac.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dac.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dac_ex.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dac_ex.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma2d.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma2d.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma_ex.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma_ex.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_exti.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_exti.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_fdcan.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_fdcan.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash_ex.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash_ex.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_gpio.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_gpio.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_hsem.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_hsem.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c_ex.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c_ex.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2s.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2s.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2s_ex.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2s_ex.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_mdma.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_mdma.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pcd.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pcd.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pcd_ex.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pcd_ex.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr_ex.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr_ex.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc_ex.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc_ex.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sd.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sd.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sd_ex.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sd_ex.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sdram.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sdram.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_spi.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_spi.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_spi_ex.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_spi_ex.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sram.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sram.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim_ex.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim_ex.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_uart.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_uart.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_uart_ex.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_uart_ex.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_delayblock.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_delayblock.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_fmc.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_fmc.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_sdmmc.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_sdmmc.o ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_usb.d ./lib/hal/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_usb.o

.PHONY: clean-lib-2f-hal-2f-Drivers-2f-STM32H7xx_HAL_Driver-2f-Src

