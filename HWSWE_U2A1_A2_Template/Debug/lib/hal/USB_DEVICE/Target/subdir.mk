################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/hal/USB_DEVICE/Target/usbd_conf.c 

OBJS += \
./lib/hal/USB_DEVICE/Target/usbd_conf.o 

C_DEPS += \
./lib/hal/USB_DEVICE/Target/usbd_conf.d 


# Each subdirectory must supply rules for building sources it contributes
lib/hal/USB_DEVICE/Target/%.o lib/hal/USB_DEVICE/Target/%.su: ../lib/hal/USB_DEVICE/Target/%.c lib/hal/USB_DEVICE/Target/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu17 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../lib/hal/Core/Inc -I../lib/libleguan/include -I../lib/hal/Drivers/STM32H7xx_HAL_Driver/Inc -I../lib/hal/Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../lib/hal/Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../lib/hal/Drivers/CMSIS/Include -I../lib/hal/FATFS/Target -I../lib/hal/FATFS/App -I../lib/hal/USB_DEVICE/App -I../lib/hal/USB_DEVICE/Target -I../lib/hal/Middlewares/Third_Party/FatFs/src -I../lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../lib/hal/Middlewares/ST/STM32_USB_Device_Library/Class/CustomHID/Inc -I../include -O0 -ffunction-sections -fdata-sections -Wall -Werror -mfp16-format=ieee -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lib-2f-hal-2f-USB_DEVICE-2f-Target

clean-lib-2f-hal-2f-USB_DEVICE-2f-Target:
	-$(RM) ./lib/hal/USB_DEVICE/Target/usbd_conf.d ./lib/hal/USB_DEVICE/Target/usbd_conf.o ./lib/hal/USB_DEVICE/Target/usbd_conf.su

.PHONY: clean-lib-2f-hal-2f-USB_DEVICE-2f-Target

