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

aux_source_directory(. SOURCE_FILES)
aux_source_directory(state_case SOURCE_FILES)

add_executable(state ${SOURCE_FILES})

add_executable(state_2 all_in_one.cpp)
