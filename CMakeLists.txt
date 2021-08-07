cmake_minimum_required(VERSION 3.19)
project(advent-c C)

set(CMAKE_C_STANDARD 11)

include_directories(libs/adt libs/intcode libs/utils)

configure_file(resources/input.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(resources/tester.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

#add_executable(advent-c main.c)
#add_executable(advent-c printer.c)
#add_executable(advent-c tripref.c)
#add_executable(advent-c copying.c)
#add_executable(advent-c src/day1.c)
add_executable(advent-c src/day2.c
        libs/intcode/intcode.c
        libs/intcode/intcode.h
        libs/utils/utils.h
        libs/utils/utils.c)
