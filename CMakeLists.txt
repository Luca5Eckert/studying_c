cmake_minimum_required(VERSION 3.20)
project(studying_c C)

set(CMAKE_C_STANDARD 11)

add_executable(studying_c main.c)

add_executable(
        dynamic_array data_structure/array_list/array_list.c
        data_structure/array_list/array_list.h
)

add_executable(
        linked_list data_structure/linked_list/linked_list.c
        data_structure/linked_list/linked_list.h
)