################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/hal/USB_DEVICE/App/usb_device.c \
../lib/hal/USB_DEVICE/App/usbd_custom_hid_if.c \
../lib/hal/USB_DEVICE/App/usbd_desc.c 

OBJS += \
./lib/hal/USB_DEVICE/App/usb_device.o \
./lib/hal/USB_DEVICE/App/usbd_custom_hid_if.o \
./lib/hal/USB_DEVICE/App/usbd_desc.o 

C_DEPS += \
./lib/hal/USB_DEVICE/App/usb_device.d \
./lib/hal/USB_DEVICE/App/usbd_custom_hid_if.d \
./lib/hal/USB_DEVICE/App/usbd_desc.d 


# Each subdirectory must supply rules for building sources it contributes
lib/hal/USB_DEVICE/App/%.o: ../lib/hal/USB_DEVICE/App/%.c lib/hal/USB_DEVICE/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu17 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../lib/hal/Core/Inc -I../lib/libleguan/include -I../lib/hal/Drivers/STM32H7xx_HAL_Driver/Inc -I../lib/hal/Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../lib/hal/Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../lib/hal/Drivers/CMSIS/Include -I../lib/hal/FATFS/Target -I../lib/hal/FATFS/App -I../lib/hal/USB_DEVICE/App -I../lib/hal/USB_DEVICE/Target -I../lib/hal/Middlewares/Third_Party/FatFs/src -I../lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../lib/hal/Middlewares/ST/STM32_USB_Device_Library/Class/CustomHID/Inc -I../include -O0 -ffunction-sections -fdata-sections -Wall -Werror -mfp16-format=ieee -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lib-2f-hal-2f-USB_DEVICE-2f-App

clean-lib-2f-hal-2f-USB_DEVICE-2f-App:
	-$(RM) ./lib/hal/USB_DEVICE/App/usb_device.d ./lib/hal/USB_DEVICE/App/usb_device.o ./lib/hal/USB_DEVICE/App/usbd_custom_hid_if.d ./lib/hal/USB_DEVICE/App/usbd_custom_hid_if.o ./lib/hal/USB_DEVICE/App/usbd_desc.d ./lib/hal/USB_DEVICE/App/usbd_desc.o

.PHONY: clean-lib-2f-hal-2f-USB_DEVICE-2f-App

