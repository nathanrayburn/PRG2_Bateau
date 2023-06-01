/*
 -----------------------------------------------------------------------------------
 Nom du fichier : bateau_affichage.h
 Auteur(s)      : Leonard Klasen, Nathan Rayburn, Keya Dessasa
 Date creation  : 25.05.2023

 Description    : Ce fichier d'en-tête contient la déclaration des fonctions
                  d'affichage.

 Remarque(s)    : -

 Compilateur    : Mingw-w64 gcc 12.2.0
 -----------------------------------------------------------------------------------
*/

#ifndef PRG2_BATEAU_BATEAU_AFFICHAGE_H
#define PRG2_BATEAU_BATEAU_AFFICHAGE_H

#include "bateau.h"
#include "taxes.h"

/**
 * Permet d'afficher la description complète d'un bateau : son nom, sa catégorie, ses taxes, etc...
 * @param bateau
 * @param taxe
 */
void afficherBateau(const Bateau *bateau, double taxe);

/**
 * Permet d'afficher tous les bateaux du port triés de manière descendante en
 * fonction des taxes
 * @param port tableau de bateaux
 * @param nbPlaces taille du tableau
 */
void afficherPort(const Bateau port[], size_t nbPlaces);

/**
 * Permet d'afficher la description d'un bateau de la categorie moteur
 * @param moteur
 */
void afficherMoteur(const Moteur *moteur);

/**
 * Permet d'afficher la surface en m^2 d'un voilier
 * @param voilier
 */
void afficherVoilier(const Voilier *voilier);

#endif //PRG2_BATEAU_BATEAU_AFFICHAGE_H
