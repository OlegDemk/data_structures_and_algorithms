################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../example_of_queues.c \
../linked_list.c \
../main.c \
../queues.c 

OBJS += \
./example_of_queues.o \
./linked_list.o \
./main.o \
./queues.o 

C_DEPS += \
./example_of_queues.d \
./linked_list.d \
./main.d \
./queues.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


