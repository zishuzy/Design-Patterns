cmake_minimum_required(VERSION 3.12)

project(behavioral-patterns)

if(NOT DEFINED ROOT_PATH)
    set(ROOT_PATH ${PROJECT_SOURCE_DIR}/..)
    message(STATUS "Set ROOT_PATH: ${ROOT_PATH}")
endif()

if(NOT DEFINED PLATFORM_CONFIG_CMAKE)
    include(${ROOT_PATH}/cmake/platform_config.cmake)
endif()

include_directories(
    ${ROOT_PATH}
)

add_subdirectory(state)
