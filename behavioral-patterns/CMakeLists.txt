cmake_minimum_required(VERSION 3.12)

project(behavioral-patterns)

if(NOT DEFINED ROOT_PATH)
    set(ROOT_PATH ${PROJECT_SOURCE_DIR}/..)
    message(STATUS "Set ROOT_PATH: ${ROOT_PATH}")
endif()

include(${ROOT_PATH}/cmake/platform_config.cmake)

include_directories(
    ${ROOT_PATH}
    ${PROJECT_SOURCE_DIR}
)

add_subdirectory(state)
add_subdirectory(chain-of-responsibility)
add_subdirectory(command)
add_subdirectory(iterator)
add_subdirectory(mediator)
add_subdirectory(memento)
add_subdirectory(observer)
add_subdirectory(strategy)
