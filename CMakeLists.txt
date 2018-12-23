
cmake_minimum_required(VERSION 3.13)

project(python-embed)

find_package(Python3 COMPONENTS Development)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/bin)

set(CMAKE_DEBUG_POSTFIX "_d")
add_subdirectory(src)
