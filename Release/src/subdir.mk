################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ADC.cpp \
../src/BBBProofOfConcept.cpp \
../src/GPIO.cpp \
../src/PWM.cpp \
../src/Servo.cpp 

OBJS += \
./src/ADC.o \
./src/BBBProofOfConcept.o \
./src/GPIO.o \
./src/PWM.o \
./src/Servo.o 

CPP_DEPS += \
./src/ADC.d \
./src/BBBProofOfConcept.d \
./src/GPIO.d \
./src/PWM.d \
./src/Servo.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabhif-g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


