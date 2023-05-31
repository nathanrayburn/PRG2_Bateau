//
// Created by nathan on 5/30/23.
//

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

//Fonctions Taxes
double taxeAnnuelle(const Bateau *b);




#endif //PRG2_BATEAU_TAXES_H
