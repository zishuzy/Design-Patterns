cmake_minimum_required(VERSION 3.12)

project(abstract-factory)

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
    factory/factory_1.cpp
    factory/factory_2.cpp
    product/product_a.cpp
    product/product_b.cpp
)

add_executable(abstract_factory ${SOURCE_FILES})
