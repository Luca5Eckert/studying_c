cmake_minimum_required(VERSION 4.1)
project(studying_c C)

set(CMAKE_C_STANDARD 11)

add_executable(studying_c main.c
        pointer/dynamic_array.c)
