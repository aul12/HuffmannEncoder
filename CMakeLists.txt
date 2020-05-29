cmake_minimum_required(VERSION 3.16)
project(Huffman)

set(CMAKE_CXX_STANDARD 20)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Werror -mtune=native -march=native")
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
endif ()

set(SOURCES
        ${CMAKE_SOURCE_DIR}/util.cpp
        ${CMAKE_SOURCE_DIR}/huffman.cpp)

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})
add_subdirectory(Tests)
