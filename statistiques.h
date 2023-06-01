/*
 -----------------------------------------------------------------------------------
 Nom du fichier : statistiques.h
 Auteur(s)      : Leonard Klasen, Nathan Rayburn, Keya Dessasa
 Date creation  : 25.05.2023

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

/**
 * Permet de calculer la somme des taxes pour une certaine catégorie de bateau
 * @param port
 * @param nbPlaces
 * @param typeBateau
 * @param casUtilisation permet de distinguer si on a un bateau de pêche ou de plaisance
 * @return double - la somme de taxe
 */
double sommeTaxes(const Port port, size_t nbPlaces, TypeBateau typeBateau,
                  CasUtilisation casUtilisation);

/**
 * Permet de calculer la moyenne des taxes pour une certaine catégorie de bateau
 * @param port
 * @param nbPlaces
 * @param typeBateau
 * @param casUtilisation permet de distinguer si on a un bateau de pêche ou de plaisance
 * @return double de la moyenne
 */
double moyenneTaxes(const Port port, size_t nbPlaces, TypeBateau typeBateau,
                    CasUtilisation casUtilisation);

/**
 * Crée un tableau qui calcule la mediane des taxes pour une certaine catégorie de bateau
 * puis envoie ce tableau à la fonction mediane qui en calcul la médiane
 * @param port
 * @param nbPlaces
 * @param typeBateau
 * @param casUtilisation
 * @return double
 */
double medianeTaxes(const Port port, size_t nbPlaces, TypeBateau typeBateau,
                    CasUtilisation casUtilisation);

/**
 * Calcule la médiane du tableau de valeurs passées en paramètre
 * @param valeurs un pointeur sur un tableau de double
 * @param taille représente le nombre d'éléments du tableau
 * @return double de la médiane
 */
double mediane(double *valeurs, size_t taille);

/**
 * Permet de calculer l'ecart-types pour une certaine catégorie de bateau
 * @param port
 * @param nbPlaces
 * @param typeBateau
 * @param casUtilisation permet de distinguer si on a un bateau de pêche ou de plaisance
 * @return double de l'ecart-types
 */
double ecTypeTaxes(const Port port, size_t nbPlaces, TypeBateau typeBateau,
                   CasUtilisation casUtilisation);

/**
 * Permet de savoir si la bateau appartient à la catégorie pêche ou plaisance ou aucune des deux
 * @param b un pointeur sur un bateau
 * @param typeBateau
 * @param casUtilisation permet de distinguer si on a un bateau de pêche ou de plaisance
 * @return bool
 */
bool appartientCatBateau(const Bateau *b, TypeBateau typeBateau,
                         CasUtilisation casUtilisation);

/**
 * Afficher les statistiques pour les 3 catégories de bateau différentes
 * @param port
 * @param nbPlaces
 */
void statistiques(const Port port, size_t nbPlaces);

/**
 * Cette fonction permet d'afficher les statistiques d'une catégorie de bateau
 * @param port
 * @param nbPlaces
 * @param typeBateau
 * @param casUtilisation permet de distinguer si on a un bateau de pêche ou de plaisance
 */
void stat(const Port port, size_t nbPlaces, TypeBateau typeBateau,
          CasUtilisation casUtilisation);

/**
 * Permet de calculer le nombre de bateaux de la catégorie
 * @param port
 * @param nbPlaces
 * @param typeBateau
 * @param casUtilisation permet de distinguer si on a un bateau de pêche ou de plaisance
 * @return size_t du nombre de bateau
 */
size_t nbBateauxCriteres(const Port port, size_t nbPlaces, TypeBateau typeBateau,
                         CasUtilisation casUtilisation);

/**
 * Fonction utilisée par qsort pour comparer les doubles et les trier
 * source: https://en.cppreference.com/w/c/algorithm/qsort
 * @param a un pointeur générique
 * @param b un pointeur générique
 * @return int
*/
int comparerDouble(const void *a, const void *b);

#endif //PRG2_BATEAU_STATISTIQUES_H

