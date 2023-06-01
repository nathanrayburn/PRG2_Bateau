/*
 -----------------------------------------------------------------------------------
 Nom du fichier : taxes.c
 Auteur(s)      : Leonard Klasen, Nathan Rayburn, Keya Dessasa
 Date creation  : 25.05.2023

 Description    : Ce fichier contient l'implémentation de la fonction
                  qui calcule la taxe annuelle d'un bateau donné.

 Remarque(s)    : -

 Compilateur    : Mingw-w64 gcc 12.2.0
 -----------------------------------------------------------------------------------
*/

#include "taxes.h"


double taxeAnnuelle(const Bateau *b) {
    assert(b);
    switch (b->typeBateau) {
        case VOILIER :
            return TAXE_BASE_VOILIER +
                   (b->caracteristiqueBateau.voilier.surfaceVoile < SURFACE_VOILIER ?
                    TAXE_SPECIFIQUE_VOILIER : TAXE_SPECIFIQUE_VOILIER_IF);

        case MOTEUR :
            if (b->caracteristiqueBateau.moteur.casUtilisation == PECHE) {
                return TAXE_BASE_MOTEUR +
                       (b->caracteristiqueBateau.moteur.typeBateauMoteur.peche.tonnagePoisson <
                       TONNE_POISSON ?
                        TAXE_SPECIFIQUE_PECHE : TAXE_SPECIFIQUE_PECHE_IF);
            } else {
                return TAXE_BASE_MOTEUR +
                       (b->caracteristiqueBateau.moteur.puissance < PUISSANCE_MOTEUR ?
                        TAXE_SPECIFIQUE_PLAISANCE : TAXE_SPECIFIQUE_PLAISANCE_IF *
                        b->caracteristiqueBateau.moteur.typeBateauMoteur.plaisance.longueur);
            }

    }
}


void calculerTaxeDescroissant(TaxeCalculeeBateau *taxeCalculeeBateaux, const Port port,
                              size_t nbPLaces) {
    assert(taxeCalculeeBateaux);
    for (size_t i = 0; i < nbPLaces; ++i) {
        taxeCalculeeBateaux[i].taxe = taxeAnnuelle(&port[i]); // taxe calculer pour chaque bateau
        taxeCalculeeBateaux[i].bateau = &port[i];
    }
    //Trier les bateaux par taxe, dans l'ordre décroissant
    qsort(taxeCalculeeBateaux, nbPLaces, sizeof(*taxeCalculeeBateaux),
          comparerTaxeDesc);
}


int comparerTaxeDesc(const void *a, const void *b) {
    return (int) ((*(TaxeCalculeeBateau *) b).taxe - (*(TaxeCalculeeBateau *) a).taxe);
}



