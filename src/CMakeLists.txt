include_directories(
    ${PROJECT_SOURCE_DIR}/v1
    ${PROJECT_SOURCE_DIR}/external
    ${PROJECT_SOURCE_DIR}/external/bleu/v1
    ${PROJECT_SOURCE_DIR}/external/malkt/v1
    )

add_library(
    golem
    actuators/motors/null_motor.c
    actuators/solenoids/null_solenoid.c
    actuators/null_actuator_transaction.c
    actuators/null_actuator.c
    sensors/microswitches/null_microswitch.c
    sensors/photosensors/null_photosensor.c
    sensors/temperature_sensors/null_temperature_sensor.c
    sensors/null_sensor.c
    golem.c
    ${PROJECT_SOURCE_DIR}/external/bleu/src/heap/gcc/heap.c
    )

add_executable(
    gtests
    actuators/motors/null_motor_test.cpp
    actuators/solenoids/null_solenoid_test.cpp
    actuators/null_actuator_test.cpp
    actuators/null_actuator_transaction_test.cpp
    sensors/microswitches/null_microswitch_test.cpp
    sensors/photosensors/null_photosensor_test.cpp
    sensors/temperature_sensors/null_temperature_sensor_test.cpp
    sensors/null_sensor_test.cpp
    golem_test.cpp
    main.cpp
    ${PROJECT_SOURCE_DIR}/external/malkt/src/utkernel/task/task_spy.c
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
