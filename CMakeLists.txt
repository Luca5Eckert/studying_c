cmake_minimum_required(VERSION 3.20) # Versão recomendada
project(studying_c C)

set(CMAKE_C_STANDARD 11)

add_executable(studying_c main.c)

add_executable(dynamic_array pointer/dynamic_array.c)