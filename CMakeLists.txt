cmake_minimum_required(VERSION 3.19)
project(day01_c C)

set(CMAKE_C_STANDARD 11)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/tester.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

#add_executable(day01_c main.c)
#add_executable(day01_c printer.c)
add_executable(day01_c tripref.c)
