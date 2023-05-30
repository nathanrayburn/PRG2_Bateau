//
// Created by nathan on 5/30/23.
//

#include "taxes.h"




double taxeAnnuelle(const Bateau *b) {
    assert(b);
    switch(b->typeBateau) {
        case VOILIER :
            return  TAXE_BASE_VOILIER +
                    b->caracteristiqueBateau.voilier.surfaceVoile < SURFACE_VOILIER ?
                    TAXE_SPECIFIQUE_VOILIER : TAXE_SPECIFIQUE_VOILIER_IF;

        case MOTEUR :
            if(b->caracteristiqueBateau.moteur.casUtilisation == PECHE) {
                return  TAXE_BASE_MOTEUR +
                        b->caracteristiqueBateau.moteur.typeBateauMoteur.peche.tonnagePoisson < TONNE_POISSON ?
                        TAXE_SPECIFIQUE_PECHE : TAXE_SPECIFIQUE_PECHE_IF;
            }

            else {
                return TAXE_BASE_MOTEUR +
                        b->caracteristiqueBateau.moteur.puissance < PUISSANCE_MOTEUR ?
                        TAXE_SPECIFIQUE_PLAISANCE : TAXE_SPECIFIQUE_PLAISANCE_IF *
                        b->caracteristiqueBateau.moteur.typeBateauMoteur.plaisance.longueur;
            }

    }
};
double taxeAnnuelleMoteur(const Moteur *m); // vis à vis de fct taxeAnnuelle = pas besoin de celle la

// Somme des taxes pour un certain type de bateau
double sommeTaxes(const Port port, size_t nbPlaces, TypeBateau typeBateau,
                  CasUtilisation catUtilis){

    assert(port);
    double sommeDesTaxes = 0;
    for(size_t i = 0; i < nbPlaces; ++i) {
        if(port[i] && appartientCatBateau(port[i], typeBateau, catUtilis)) {
            sommeDesTaxes += taxeAnnuelle(port[i]);
        }
    }

}

// Moyenne des taxes pour un certain type de bateau
double moyenneTaxes(const Port port, size_t nbPlaces, TypeBateau typeBateau,
                    CasUtilisation catUtilis) {
    assert(port);
    size_t nbrBateauParCat = 0;
    double somme = 0;
    for(size_t i = 0; i < nbPlaces; ++i) {
        if(port[i] && appartientCatBateau(port[i], typeBateau, catUtilis)) {
            ++nbrBateauParCat;
            somme += taxeAnnuelle(port[i]);
        }
    }
    return somme / nbrBateauParCat;
}

// Allocation dynamique
// Permet de créer un tableau contenant les taxes annuelles pour les bateau de chaque catégorie
// et d'envoyer ce tableau à la fonction mediane qui va calculer sa médiane
double medianeTaxes(const Port port, size_t nbPlaces, TypeBateau typeBateau,
                    CasUtilisation catUtilis);

double mediane(double *valeurs, size_t taille) {
    assert(valeurs);
    qsort(valeurs, taille, sizeof(double) )
}

int compareDouble(const void *a).... // a finir

double ecTypeTaxes(const Port port, size_t nbPlaces, TypeBateau typeBateau,
                   CasUtilisation catUtilis);

