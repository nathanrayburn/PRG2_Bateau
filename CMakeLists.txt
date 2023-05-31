cmake_minimum_required(VERSION 3.23.2)
project(PRG2_Bateau C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(bateau.h bateau.c main.c bateau_affichage.h bateau_affichage.c statistiques.h statistiques.c taxes.h taxes.c)
