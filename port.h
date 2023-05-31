//
// Created by nathanrayburn on 31/05/2023.
//

#ifndef PRG2_BATEAU_PORT_H
#define PRG2_BATEAU_PORT_H
#include "bateau.h"
typedef struct{
    double taxe;
    const Bateau* bateau;
} TaxeCalc;
void afficherBateauxTaxeDesc(const Bateau* port, size_t taille);
int comparerTaxe(void *a, void *b);

#endif //PRG2_BATEAU_PORT_H

#include "bateau.h"

void afficherBateauxParTaxeDesc(const Bateau* bateau, size_t taille);


void afficherBateauxStatistiquesParCat(const Bateau* bateau, size_t taille);

int compTaxeDescendant(const void* a, const void* b);