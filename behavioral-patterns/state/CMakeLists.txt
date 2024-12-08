cmake_minimum_required(VERSION 3.12)

project(state)

if(NOT DEFINED ROOT_PATH)
    set(ROOT_PATH ${PROJECT_SOURCE_DIR}/../..)
    message(STATUS "Set ROOT_PATH: ${ROOT_PATH}")
endif()

include(${ROOT_PATH}/cmake/platform_config.cmake)

include_directories(
    ${ROOT_PATH}
    ${PROJECT_SOURCE_DIR}
)

set(SOURCE_FILES
    main.cpp
    context.cpp
    state_case/state_home.cpp
    state_case/state_repair_aborting.cpp
    state_case/state_repaired.cpp
    state_case/state_repairing.cpp
    state_case/state_repair_pausing.cpp
    state_case/state_scan_aborting.cpp
    state_case/state_scanned.cpp
    state_case/state_scanning.cpp
    state_case/state_scan_pausing.cpp
)

add_executable(state ${SOURCE_FILES})
