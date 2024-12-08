cmake_minimum_required(VERSION 3.12)

project(creational-patterns)

if(NOT DEFINED ROOT_PATH)
    set(ROOT_PATH ${PROJECT_SOURCE_DIR}/..)
    message(STATUS "Set ROOT_PATH: ${ROOT_PATH}")
endif()

include(${ROOT_PATH}/cmake/platform_config.cmake)

include_directories(
    ${ROOT_PATH}
)

add_subdirectory(factory-method)
add_subdirectory(abstract-factory)
add_subdirectory(builder)
add_subdirectory(prototype)
add_subdirectory(singleton)
