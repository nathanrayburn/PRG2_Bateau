//
// Created by nathanrayburn on 31/05/2023.
//
#include <inttypes.h>
#include "bateau_affichage.h"
#include "taxes.h"

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

/**
 * Affiche les informations sur tous les bateaux d'un port
 * @param port Pointeur sur le port
 * @param nbPlaces Nombre de place du port
 */
void afficherPort(const Port port, size_t nbPlaces) {
    assert(port);
    printf("Listes des bateaux du port:\n");
    for (size_t i = 0; i < nbPlaces; ++i) {
        if (port[i]) {
            printf("#%" PRIu64 "\n", i);
            afficherBateau(port[i]);
        }
    }
}