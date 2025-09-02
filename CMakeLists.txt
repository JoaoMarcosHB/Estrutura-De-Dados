cmake_minimum_required(VERSION 4.0)
project(DataStructures C)

set(CMAKE_C_STANDARD 11)

add_executable(DataStructures teste.c
        tab.c
        tab.h)

add_executable(teste2 main.c
        tab.c
        tab.h)

