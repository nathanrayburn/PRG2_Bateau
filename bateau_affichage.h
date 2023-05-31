/*
 -----------------------------------------------------------------------------------
 Nom du fichier : bateau_affichage.h
 Auteur(s)      : Leonard Klasen, Nathan Rayburn, Keya Dessasa
 Date creation  : 31.05.2023

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

void afficherBateau(const Bateau *bateau, double taxe);

void afficherPort(const Bateau port[], size_t nbPlaces);

void afficherMoteur(const Moteur *moteur);

void afficherVoilier(const Voilier *voilier);

void afficherOrdreDecroissant(const Bateau *bateau, size_t nbPlaces);

#endif //PRG2_BATEAU_BATEAU_AFFICHAGE_H
