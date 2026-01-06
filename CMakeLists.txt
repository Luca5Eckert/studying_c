cmake_minimum_required(VERSION 3.20)
project(studying_c C)

set(CMAKE_C_STANDARD 11)

add_executable(studying_c main.c)

add_executable(dynamic_array data_structure/dynamic_array/numbers.c
        data_structure/dynamic_array/numbers.h)