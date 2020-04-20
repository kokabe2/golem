include_directories(
    ${PROJECT_SOURCE_DIR}/v1
    ${PROJECT_SOURCE_DIR}/external
    ${PROJECT_SOURCE_DIR}/external/bleu/v1
    ${PROJECT_SOURCE_DIR}/external/malkt/v1
    )

add_library(
    golem
    actuators/motors/pulse_motors/null_pulse_motor.c
    actuators/motors/pulse_motors/pulse_motor.c
    actuators/motors/motor.c
    actuators/motors/null_motor.c
    actuators/solenoids/null_solenoid.c
    actuators/solenoids/solenoid.c
    actuators/actuator.c
    actuators/null_actuator.c
    displays/leds/led_arrays/led_array.c
    displays/leds/led_arrays/null_led_array.c
    displays/leds/led.c
    displays/leds/null_led.c
    displays/seven_segment_displays/null_seven_segment_display.c
    displays/seven_segment_displays/seven_segment_display.c
    displays/null_display.c
    sensors/microswitches/null_microswitch.c
    sensors/photosensors/null_photosensor.c
    sensors/temperature_sensors/null_temperature_sensor.c
    sensors/null_sensor.c
    ${PROJECT_SOURCE_DIR}/external/bleu/src/heap/gcc/heap.c
    ${PROJECT_SOURCE_DIR}/external/bleu/src/heap/heap_usage.c
    )

add_executable(
    gtests
    main.cpp
    actuators/motors/pulse_motors/null_pulse_motor_test.cpp
    actuators/motors/null_motor_test.cpp
    actuators/solenoids/null_solenoid_test.cpp
    actuators/null_actuator_test.cpp
    displays/leds/led_arrays/null_led_array_test.cpp
    displays/leds/null_led_test.cpp
    displays/seven_segment_displays/null_seven_segment_display_test.cpp
    displays/null_display_test.cpp
    sensors/microswitches/null_microswitch_test.cpp
    sensors/photosensors/null_photosensor_test.cpp
    sensors/temperature_sensors/null_temperature_sensor_test.cpp
    sensors/null_sensor_test.cpp
    )

add_dependencies(gtests googletest)

target_link_libraries(
    gtests
    googletest
    golem
    pthread
    )

include(CTest)

add_test(golem_test ${PROJECT_BINARY_DIR}/gtests)
