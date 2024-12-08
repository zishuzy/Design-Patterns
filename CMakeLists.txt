cmake_minimum_required(VERSION 3.12)

project(design-patterns)

include(cmake/platform_config.cmake)

set(ROOT_START ON)
set(ROOT_PATH ${PROJECT_SOURCE_DIR})
message(STATUS "Set ROOT_PATH: ${ROOT_PATH}")

include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(creational-patterns)
add_subdirectory(structural-patterns)
add_subdirectory(behavioral-patterns)
