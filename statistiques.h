/*
 -----------------------------------------------------------------------------------
 Nom du fichier : statistiques.h
 Auteur(s)      : Leonard Klasen, Nathan Rayburn, Keya Dessasa
 Date creation  : 31.05.2023

 Description    : Ce fichier d'en-tête contient la déclaration des fonctions
                  calculant les différentes statistiques d'un port donné.

 Remarque(s)    : -

 Compilateur    : Mingw-w64 gcc 12.2.0
 -----------------------------------------------------------------------------------
*/

#ifndef PRG2_BATEAU_STATISTIQUES_H
#define PRG2_BATEAU_STATISTIQUES_H

#include "bateau.h"
#include "taxes.h"
#include <assert.h>

double sommeTaxes(const Port port, size_t nbPlaces, TypeBateau typeBateau,
                  CasUtilisation catUtilis);

double moyenneTaxes(const Port port, size_t nbPlaces, TypeBateau typeBateau,
                    CasUtilisation catUtilis);


double medianeTaxes(const Port port, size_t nbPlaces, TypeBateau typeBateau,
                    CasUtilisation catUtilis);

double mediane(double *valeurs, size_t taille);

double ecTypeTaxes(const Port port, size_t nbPlaces, TypeBateau typeBateau,
                   CasUtilisation catUtilis);

bool appartientCatBateau(const Bateau *b, TypeBateau typeBateau,
                         CasUtilisation casUtilisation);

void statistiques(const Port port, size_t nbPlaces);

void stat(const Port port, size_t nbPlaces, TypeBateau typeBateau,
          CasUtilisation casUtilisation);

size_t nbBateauxCriteres(const Port port, size_t nbPlaces, TypeBateau typeBateau,
                         CasUtilisation casUtilisation);

#endif //PRG2_BATEAU_STATISTIQUES_H

