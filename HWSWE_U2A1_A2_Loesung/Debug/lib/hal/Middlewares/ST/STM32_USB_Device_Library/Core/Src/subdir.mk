################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.c \
../lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.c \
../lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.c 

OBJS += \
./lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.o \
./lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.o \
./lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.o 

C_DEPS += \
./lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.d \
./lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.d \
./lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.d 


# Each subdirectory must supply rules for building sources it contributes
lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Src/%.o lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Src/%.su lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Src/%.cyclo: ../lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Src/%.c lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu17 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../lib/hal/Core/Inc -I../lib/libleguan/include -I../lib/hal/Drivers/STM32H7xx_HAL_Driver/Inc -I../lib/hal/Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../lib/hal/Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../lib/hal/Drivers/CMSIS/Include -I../lib/hal/FATFS/Target -I../lib/hal/FATFS/App -I../lib/hal/USB_DEVICE/App -I../lib/hal/USB_DEVICE/Target -I../lib/hal/Middlewares/Third_Party/FatFs/src -I../lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../lib/hal/Middlewares/ST/STM32_USB_Device_Library/Class/CustomHID/Inc -I../include -O0 -ffunction-sections -fdata-sections -Wall -Werror -mfp16-format=ieee -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lib-2f-hal-2f-Middlewares-2f-ST-2f-STM32_USB_Device_Library-2f-Core-2f-Src

clean-lib-2f-hal-2f-Middlewares-2f-ST-2f-STM32_USB_Device_Library-2f-Core-2f-Src:
	-$(RM) ./lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.cyclo ./lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.d ./lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.o ./lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.su ./lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.cyclo ./lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.d ./lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.o ./lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.su ./lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.cyclo ./lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.d ./lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.o ./lib/hal/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.su

.PHONY: clean-lib-2f-hal-2f-Middlewares-2f-ST-2f-STM32_USB_Device_Library-2f-Core-2f-Src

