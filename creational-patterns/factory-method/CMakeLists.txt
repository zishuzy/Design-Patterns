cmake_minimum_required(VERSION 3.12)

project(factory-method)

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
    factory/factory_a.cpp
    factory/factory_b.cpp
    product/product_a.cpp
    product/product_b.cpp
)

add_executable(factory_method ${SOURCE_FILES})
