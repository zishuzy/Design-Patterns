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

aux_source_directory(. SOURCE_FILES)
aux_source_directory(product SOURCE_FILES)
aux_source_directory(factory SOURCE_FILES)

add_executable(factory_method ${SOURCE_FILES})
