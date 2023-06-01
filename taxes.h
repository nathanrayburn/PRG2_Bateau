/*
 -----------------------------------------------------------------------------------
 Nom du fichier : taxes.h
 Auteur(s)      : Leonard Klasen, Nathan Rayburn, Keya Dessasa
 Date creation  : 25.05.2023

 Description    : Ce fichier d'en-tête contient la déclaration de la fonction
                  qui calcule la taxe annuelle d'un bateau donné.

 Remarque(s)    : -

 Compilateur    : Mingw-w64 gcc 12.2.0
 -----------------------------------------------------------------------------------
*/

#ifndef PRG2_BATEAU_TAXES_H
#define PRG2_BATEAU_TAXES_H

#include "bateau.h"
#include <assert.h>

//Taxes
#define TAXE_BASE_VOILIER 50
#define TAXE_BASE_MOTEUR 100
#define TAXE_SPECIFIQUE_VOILIER 0
#define TAXE_SPECIFIQUE_VOILIER_IF 25
#define TAXE_SPECIFIQUE_PECHE 0
#define TAXE_SPECIFIQUE_PECHE_IF 100
#define TAXE_SPECIFIQUE_PLAISANCE 50
#define TAXE_SPECIFIQUE_PLAISANCE_IF 15
#define SURFACE_VOILIER 200
#define TONNE_POISSON 20
#define PUISSANCE_MOTEUR 100


typedef struct {
    double taxe;
    const Bateau *bateau;
} TaxeCalculeeBateau;

/**
 * Calcule la taxe annuelle en fonction de la catégorie du bateau et de son utilisation
 * @param un pointeur sur un bateau
 * @return un double de la taxe annuellle
 */
double taxeAnnuelle(const Bateau *b);

/**
 * Permet de calculer les taxes de chaque bateaux et de les trier dans l'ordre descroissant
 * @param taxeCalculeeBateaux Un pointeur sur un tableau
 * @param port
 * @param nbPLaces
 */
void calculerTaxeDescroissant(TaxeCalculeeBateau *taxeCalculeeBateaux, const Port port, size_t nbPLaces);

/**
 * Fonction de comparaison descendant pour les taxes pour les trier grâce au qsort
 * @param a Un pointeur générique sur un élément du tableau TaxeCalculeeBateau
 * @param b Un pointeur générique sur un élément du tableau TaxceCalculeeBateau
 * @return int
 */
int comparerTaxeDesc(const void *a, const void *b);

#endif //PRG2_BATEAU_TAXES_H
