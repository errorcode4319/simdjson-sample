cmake_policy(SET CMP0048 NEW)
project(simdjson-sample VERSION 1.1.0 LANGUAGES CXX)

cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED On)
add_compile_options(-O2 -Wno-dev)

add_subdirectory(simdjson)

add_executable(sample src/main.cpp)
target_link_libraries(sample PRIVATE simdjson)