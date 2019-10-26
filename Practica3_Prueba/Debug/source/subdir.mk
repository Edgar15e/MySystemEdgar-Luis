################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/Carrito.c \
../source/Debouncer.c \
../source/GPIO_Driver.c \
../source/PWM_Driver.c \
../source/Tacometer.c \
../source/Transmision.c \
../source/UART0_Driver.c 

OBJS += \
./source/Carrito.o \
./source/Debouncer.o \
./source/GPIO_Driver.o \
./source/PWM_Driver.o \
./source/Tacometer.o \
./source/Transmision.o \
./source/UART0_Driver.o 

C_DEPS += \
./source/Carrito.d \
./source/Debouncer.d \
./source/GPIO_Driver.d \
./source/PWM_Driver.d \
./source/Tacometer.d \
./source/Transmision.d \
./source/UART0_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__REDLIB__ -I../board -I../source -I../ -I../drivers -I../CMSIS -I../utilities -I../startup -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


