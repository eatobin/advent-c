cmake_minimum_required(VERSION 3.19)
project(advent-c C)

set(CMAKE_C_STANDARD 11)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/tester.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

#add_executable(advent-c main.c)
#add_executable(advent-c printer.c)
add_executable(advent-c tripref.c)
#add_executable(advent-c copying.c)
