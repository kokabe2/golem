include_directories(
    ${PROJECT_SOURCE_DIR}/v1
    ${PROJECT_SOURCE_DIR}/external
    ${PROJECT_SOURCE_DIR}/external/bleu/v1
    ${PROJECT_SOURCE_DIR}/external/malkt/v1
    )

add_library(
    golem
    sensors/photosensors/null_photosensor.c
    sensors/microswitches/null_microswitch.c
    sensors/null_sensor.c
    golem.c
    ${PROJECT_SOURCE_DIR}/external/bleu/src/heap/gcc/heap.c
    )

add_executable(
    gtests
    sensors/photosensors/null_photosensor_test.cpp
    sensors/microswitches/null_microswitch_test.cpp
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
