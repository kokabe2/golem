@echo off

set PROJECT_NAME=golem
for /F "tokens=*" %%A in ('"git describe HEAD --abbrev=0"') do set PROJECT_VER=%%A

cd %~dp0

set COMPILER=ccrx
set OUTPUT_DIR=bin\%COMPILER%@%PROJECT_VER%
mkdir %OUTPUT_DIR% > NUL 2>&1
%COMPILER% -output=obj -lang=c99 -nostuff -isa=rxv3 -debug -signed_char ^
           -include=v1/,external/ ^
           src/sensors/microswitches/microswitch.c ^
           src/sensors/null_sensor.c ^
           src/sensors/sensor_factory.c ^
           src/sensors/sensor.c ^
           src/util/active_object_engine_task.c ^
           src/util/active_object_engine.c ^
           src/util/error_command.c ^
           src/util/null_command.c ^
           src/util/simple_active_object_engine.c ^
           src/util/sleep_command.c ^
           src/command.c
if %errorlevel% neq 0 exit /b

rlink -form=lib -output=%OUTPUT_DIR%/%PROJECT_NAME%.lib *.obj
del *.obj
