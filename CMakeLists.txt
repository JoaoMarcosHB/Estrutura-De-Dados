cmake_minimum_required(VERSION 4.0)
project(DataStructures C)

set(CMAKE_C_STANDARD 11)

add_executable(DataStructures teste.c
        tab/tab.c
        tab/tab.h)

add_executable(teste2 main.c
        tab/tab.c
        tab/tab.h)

add_executable(lista1ex1 lista1/lista1ex1.c
        tab/tab.c
        tab/tab.h
)
add_executable(lista1ex6 lista1/lista1ex6.c
        tab/tab.c
        tab/tab.h
)
