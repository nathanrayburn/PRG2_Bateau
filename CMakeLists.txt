cmake_minimum_required(VERSION 3.25)
project(PRG2_Bateau C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(PRG2_Bateau
        bateau.c
        bateau.h
        main.c)
