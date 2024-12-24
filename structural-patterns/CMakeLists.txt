cmake_minimum_required(VERSION 3.12)

project(structural-patterns)

if(NOT DEFINED ROOT_PATH)
    set(ROOT_PATH ${PROJECT_SOURCE_DIR}/..)
    message(STATUS "Set ROOT_PATH: ${ROOT_PATH}")
endif()

include(${ROOT_PATH}/cmake/platform_config.cmake)

include_directories(
    ${ROOT_PATH}
    ${PROJECT_SOURCE_DIR}
)

add_subdirectory(adapter)
add_subdirectory(bridge)
add_subdirectory(composite)
add_subdirectory(decorator)
add_subdirectory(facade)
add_subdirectory(flyweight)
add_subdirectory(proxy)
