include_directories(
    ${PROJECT_SOURCE_DIR}/v1
    ${PROJECT_SOURCE_DIR}/external
    ${PROJECT_SOURCE_DIR}/external/bleu/v1
    ${PROJECT_SOURCE_DIR}/external/malkt/v1
    )

add_library(
    golem
    sensors/null_sensor.c
    sensors/sensor.c
    util/active_object_engine_task.c
    util/active_object_engine.c
    util/error_command.c
    util/null_command.c
    util/simple_active_object_engine.c
    util/sleep_command.c
    ${PROJECT_SOURCE_DIR}/external/bleu/src/heap/gcc/heap.c
    ${PROJECT_SOURCE_DIR}/external/bleu/src/heap/heap_usage.c
    ${PROJECT_SOURCE_DIR}/external/bleu/src/list/list_node.c
    ${PROJECT_SOURCE_DIR}/external/bleu/src/list/list.c
    command.c
    )

add_executable(
    gtests
    sensors/null_sensor_test.cpp
    util/null_command_test.cpp
    util/simple_active_object_engine_test.cpp
    util/error_command_test.cpp
    util/sleep_command_test.cpp
    util/time_unit_stub.c
    main.cpp
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
