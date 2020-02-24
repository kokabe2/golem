@echo off

set PROJECT_NAME=golem
for /F "tokens=*" %%A in ('"git describe HEAD --abbrev=0"') do set PROJECT_VER=%%A

cd %~dp0

set COMPILER=ccrx
set OUTPUT_DIR=bin\%COMPILER%@%PROJECT_VER%
mkdir %OUTPUT_DIR% > NUL 2>&1
%COMPILER% -output=obj=%OUTPUT_DIR%/%PROJECT_NAME%.obj -lang=c99 -nostuff -isa=rxv3 ^
           -include=v1/,external/ ^
           src/sensors/microswitches/null_microswitch.c ^
           src/sensors/photosensors/null_photosensor.c ^
           src/sensors/null_sensor.c ^
           src/golem.c
if %errorlevel% neq 0 exit /b
rlink -form=lib -output=%OUTPUT_DIR%/%PROJECT_NAME%.lib ^
      %OUTPUT_DIR%/%PROJECT_NAME%.obj
