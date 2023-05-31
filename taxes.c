//
// Created by nathan on 5/30/23.
//

#include "taxes.h"




double taxeAnnuelle(const Bateau *b) {
    assert(b);
    switch(b->typeBateau) {
        case VOILIER :
            return  TAXE_BASE_VOILIER +
                    (b->caracteristiqueBateau.voilier.surfaceVoile < SURFACE_VOILIER ?
                    TAXE_SPECIFIQUE_VOILIER : TAXE_SPECIFIQUE_VOILIER_IF);

        case MOTEUR :
            if(b->caracteristiqueBateau.moteur.casUtilisation == PECHE) {
                return  TAXE_BASE_MOTEUR +
                        (b->caracteristiqueBateau.moteur.typeBateauMoteur.peche.tonnagePoisson < TONNE_POISSON ?
                        TAXE_SPECIFIQUE_PECHE : TAXE_SPECIFIQUE_PECHE_IF);
            }

            else {
                return TAXE_BASE_MOTEUR +
                        (b->caracteristiqueBateau.moteur.puissance < PUISSANCE_MOTEUR ?
                        TAXE_SPECIFIQUE_PLAISANCE : TAXE_SPECIFIQUE_PLAISANCE_IF *
                        b->caracteristiqueBateau.moteur.typeBateauMoteur.plaisance.longueur);
            }

    }
};



