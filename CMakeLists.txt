cmake_minimum_required(VERSION 3.20)

project(advent C)

set(CMAKE_C_STANDARD 11)

configure_file(resources/input.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

add_executable(day01
        src/day01.c)
