################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
A51_UPPER_SRCS += \
/home/tadashi/Downloads/SimplicityStudio_v5/developer/sdks/8051/v4.2.0/Device/shared/si8051Base/SILABS_STARTUP.A51 

C_SRCS += \
../src/InitDevice.c \
../src/Ultrasonic_sensor_main.c \
../src/delay.c \
../src/serial.c 

OBJS += \
./src/InitDevice.OBJ \
./src/SILABS_STARTUP.OBJ \
./src/Ultrasonic_sensor_main.OBJ \
./src/delay.OBJ \
./src/serial.OBJ 


# Each subdirectory must supply rules for building sources it contributes
src/%.OBJ: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Compiler'
	wine "/home/tadashi/Downloads/SimplicityStudio_v5/developer/toolchains/keil_8051/9.60/BIN/C51" "@$(patsubst %.OBJ,%.__i,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

src/InitDevice.OBJ: /home/tadashi/Downloads/SimplicityStudio_v5/developer/sdks/8051/v4.2.0/Device/EFM8LB1/inc/SI_EFM8LB1_Register_Enums.h /home/tadashi/SimplicityStudio/v5_workspace/Ultrasonic_sensor/inc/InitDevice.h /home/tadashi/Downloads/SimplicityStudio_v5/developer/sdks/8051/v4.2.0/Device/EFM8LB1/inc/SI_EFM8LB1_Defs.h /home/tadashi/Downloads/SimplicityStudio_v5/developer/sdks/8051/v4.2.0/Device/shared/si8051Base/si_toolchain.h /home/tadashi/Downloads/SimplicityStudio_v5/developer/sdks/8051/v4.2.0/Device/shared/si8051Base/stdint.h /home/tadashi/Downloads/SimplicityStudio_v5/developer/sdks/8051/v4.2.0/Device/shared/si8051Base/stdbool.h

src/SILABS_STARTUP.OBJ: /home/tadashi/Downloads/SimplicityStudio_v5/developer/sdks/8051/v4.2.0/Device/shared/si8051Base/SILABS_STARTUP.A51
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Assembler'
	wine "/home/tadashi/Downloads/SimplicityStudio_v5/developer/toolchains/keil_8051/9.60/BIN/AX51" "@$(patsubst %.OBJ,%.__ia,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

src/Ultrasonic_sensor_main.OBJ: /home/tadashi/Downloads/SimplicityStudio_v5/developer/sdks/8051/v4.2.0/Device/EFM8LB1/inc/SI_EFM8LB1_Register_Enums.h /home/tadashi/SimplicityStudio/v5_workspace/Ultrasonic_sensor/inc/InitDevice.h /home/tadashi/SimplicityStudio/v5_workspace/Ultrasonic_sensor/inc/serial.h /home/tadashi/SimplicityStudio/v5_workspace/Ultrasonic_sensor/inc/delay.h /home/tadashi/Downloads/SimplicityStudio_v5/developer/sdks/8051/v4.2.0/Device/EFM8LB1/inc/SI_EFM8LB1_Defs.h /home/tadashi/Downloads/SimplicityStudio_v5/developer/toolchains/keil_8051/9.60/INC/STDIO.H /home/tadashi/Downloads/SimplicityStudio_v5/developer/sdks/8051/v4.2.0/Device/shared/si8051Base/stdint.h /home/tadashi/Downloads/SimplicityStudio_v5/developer/sdks/8051/v4.2.0/Device/shared/si8051Base/si_toolchain.h /home/tadashi/Downloads/SimplicityStudio_v5/developer/sdks/8051/v4.2.0/Device/shared/si8051Base/stdbool.h

src/delay.OBJ: /home/tadashi/SimplicityStudio/v5_workspace/Ultrasonic_sensor/inc/delay.h /home/tadashi/Downloads/SimplicityStudio_v5/developer/sdks/8051/v4.2.0/Device/EFM8LB1/inc/SI_EFM8LB1_Register_Enums.h /home/tadashi/Downloads/SimplicityStudio_v5/developer/toolchains/keil_8051/9.60/INC/STDIO.H /home/tadashi/Downloads/SimplicityStudio_v5/developer/sdks/8051/v4.2.0/Device/shared/si8051Base/stdint.h /home/tadashi/Downloads/SimplicityStudio_v5/developer/sdks/8051/v4.2.0/Device/EFM8LB1/inc/SI_EFM8LB1_Defs.h /home/tadashi/Downloads/SimplicityStudio_v5/developer/sdks/8051/v4.2.0/Device/shared/si8051Base/si_toolchain.h /home/tadashi/Downloads/SimplicityStudio_v5/developer/sdks/8051/v4.2.0/Device/shared/si8051Base/stdbool.h

src/serial.OBJ: /home/tadashi/SimplicityStudio/v5_workspace/Ultrasonic_sensor/inc/serial.h /home/tadashi/Downloads/SimplicityStudio_v5/developer/sdks/8051/v4.2.0/Device/EFM8LB1/inc/SI_EFM8LB1_Register_Enums.h /home/tadashi/Downloads/SimplicityStudio_v5/developer/sdks/8051/v4.2.0/Device/EFM8LB1/inc/SI_EFM8LB1_Defs.h /home/tadashi/Downloads/SimplicityStudio_v5/developer/sdks/8051/v4.2.0/Device/shared/si8051Base/si_toolchain.h /home/tadashi/Downloads/SimplicityStudio_v5/developer/sdks/8051/v4.2.0/Device/shared/si8051Base/stdint.h /home/tadashi/Downloads/SimplicityStudio_v5/developer/sdks/8051/v4.2.0/Device/shared/si8051Base/stdbool.h


