@echo off

set PROJECT_NAME=golem
for /F "tokens=*" %%A in ('"git describe HEAD --abbrev=0"') do set PROJECT_VER=%%A

cd %~dp0

set COMPILER=ccrx
set OUTPUT_DIR=bin\%COMPILER%@%PROJECT_VER%
mkdir %OUTPUT_DIR% > NUL 2>&1
%COMPILER% -output=obj -lang=c99 -nostuff -isa=rxv3 -debug -signed_char ^
           -include=v1/,external/ ^
           src/actuators/motors/pulse_motors/null_pulse_motor.c ^
           src/actuators/motors/pulse_motors/pulse_motor.c ^
           src/actuators/motors/motor.c ^
           src/actuators/motors/null_motor.c ^
           src/actuators/solenoids/null_solenoid.c ^
           src/actuators/null_actuator.c ^
           src/displays/leds/led_arrays/null_led_array.c ^
           src/displays/leds/null_led.c ^
           src/displays/seven_segment_displays/null_seven_segment_display.c ^
           src/displays/null_display.c ^
           src/sensors/microswitches/null_microswitch.c ^
           src/sensors/photosensors/null_photosensor.c ^
           src/sensors/temperature_sensors/null_temperature_sensor.c ^
           src/sensors/null_sensor.c
if %errorlevel% neq 0 exit /b

rlink -form=lib -output=%OUTPUT_DIR%/%PROJECT_NAME%.lib *.obj
del *.obj
