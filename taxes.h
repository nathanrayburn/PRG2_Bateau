//
// Created by nathan on 5/30/23.
//

#ifndef PRG2_BATEAU_TAXES_H
#define PRG2_BATEAU_TAXES_H

#include "bateau.h"
#include <assert.h>

//Taxes
const double TAXE_BASE_VOILIER 				= 50;
const double TAXE_BASE_MOTEUR 				= 100;
const double TAXE_SPECIFIQUE_VOILIER 		= 0;
const double TAXE_SPECIFIQUE_VOILIER_IF 	= 25;
const double TAXE_SPECIFIQUE_PECHE 			= 0;
const double TAXE_SPECIFIQUE_PECHE_IF 		= 100;
const double TAXE_SPECIFIQUE_PLAISANCE 	    = 50;
const double TAXE_SPECIFIQUE_PLAISANCE_IF	= 15;
const uint16_t SURFACE_VOILIER 				= 200;
const uint8_t TONNE_POISSON					= 20;
const uint16_t PUISSANCE_MOTEUR				= 100;

//Fonctions Taxes
double taxeAnnuelle(const Bateau *b);




#endif //PRG2_BATEAU_TAXES_H
