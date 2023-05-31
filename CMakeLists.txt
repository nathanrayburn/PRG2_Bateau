cmake_minimum_required(VERSION 3.23.2)
project(PRG2_Bateau C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(main.c bateau.c bateau.h bateau_affichage.c bateau_affichage.h port.c port.h taxes.c taxes.h)
