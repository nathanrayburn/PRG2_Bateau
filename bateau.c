/*
 -----------------------------------------------------------------------------------
 Nom du fichier :
 Auteur(s)      :
 Date creation  :
 Description    :
 Remarque(s)    :
 Compilateur    : Mingw-w64 gcc 8.1.0
 -----------------------------------------------------------------------------------
*/

#include "bateau.h"
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include "taxes.h"


// Messages
#define DEVISE "Euros"

void afficherVoilier(const Voilier *voilier) {
    assert(voilier);
    printf("Surface de voile : %d m2", voilier->surfaceVoile);
}

void afficherMoteur(const Moteur *moteur) {
    assert(moteur);
    printf("Cas d'utilisation : %s", casUtilisationString[moteur->casUtilisation]);
    printf("Puissance : %d CV", moteur->puissance);
    switch (moteur->casUtilisation) {
        case PECHE:
            printf("Tonnage de poisson : %d", moteur->typeBateauMoteur.peche.tonnagePoisson);
            break;
        case PLAISANCE:
            printf("Nom du propriétaire : %s", moteur->typeBateauMoteur.plaisance.nomProprietaire);
            printf("Longueur : %d", moteur->typeBateauMoteur.plaisance.longueur);
            break;
    }
}

void afficherBateau(const Bateau *bateau) {
    assert(bateau);
    printf("Nom", bateau->nomBateau);
    printf("Genre", typeBateauString[bateau->typeBateau]);
    switch (bateau->typeBateau) {
        case VOILIER:
            afficherVoilier(&bateau->caracteristiqueBateau.voilier);
            break;
        case MOTEUR:
            afficherMoteur(&bateau->caracteristiqueBateau.moteur);
            break;
    }
    printf("Taxe annuelle : %d %s", taxeAnnuelle(bateau), DEVISE);
    printf("\n");
}

int comparerTaxeDesc(const void *a, const void *b) {
    assert(a);
    assert(b);
    const Bateau *bateauA = a;
    const Bateau *bateauB = b;
    return taxeAnnuelle(bateauB) - taxeAnnuelle(bateauA);
}

void triTaxes(Port *port, size_t taille) {
    while (*port != NULL) {
        qsort(port, taille, sizeof(Bateau), comparerTaxeDesc);
    }
}

void afficherPort(Bateau *const *port, size_t nbPlaces) {
    assert(port);
    printf("Listes des bateaux du port: \n");
    for (int i = 0; i < nbPlaces; ++i) {
        printf("#%\n", i);
        afficherBateau(port[i]);
    }
}

bool appartientCatBateau(const Bateau *b, TypeBateau typeBateau,
                         CasUtilisation casUtilisation) {

    assert(b);
    switch (typeBateau) {
        case VOILIER :
            return b->typeBateau == VOILIER;

        case MOTEUR :
            return b->typeBateau == MOTEUR && b->caracteristiqueBateau.moteur.casUtilisation == casUtilisation;

    }
}

