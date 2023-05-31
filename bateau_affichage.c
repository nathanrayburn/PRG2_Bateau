//
// Created by nathanrayburn on 31/05/2023.
//
#include <inttypes.h>
#include "bateau_affichage.h"
#include "taxes.h"


void afficherVoilier(const Voilier *voilier) {
    assert(voilier);
    printf("Surface de voile : %d m2\n", voilier->surfaceVoile);
}

void afficherMoteur(const Moteur *moteur) {
    assert(moteur);
    printf("Cas d'utilisation : %-20s\n", casUtilisationString[moteur->casUtilisation]);
    printf("Puissance : %d CV\n", moteur->puissance);
    switch (moteur->casUtilisation) {
        case PECHE:
            printf("Tonnage de poisson : %d\n", moteur->typeBateauMoteur.peche.tonnagePoisson);
            break;
        case PLAISANCE:
            printf("Nom du proprietaire : %-20s\n", moteur->typeBateauMoteur.plaisance.nomProprietaire);
            printf("Longueur : %d\n", moteur->typeBateauMoteur.plaisance.longueur);
            break;
    }
}

void afficherBateau(const Bateau *bateau) {
    assert(bateau);
    printf("Nom   : %-20s\n", bateau->nomBateau);
    printf("Genre : %-10s\n", typeBateauString[bateau->typeBateau]);
    switch (bateau->typeBateau) {
        case VOILIER:
            afficherVoilier(&bateau->caracteristiqueBateau.voilier);
            break;
        case MOTEUR:
            afficherMoteur(&bateau->caracteristiqueBateau.moteur);
            break;
    }
    double prix = taxeAnnuelle(bateau);
    printf("Taxe annuelle : %10.2f %s\n", prix, DEVISE);

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
        printf("#%" PRIu64 "\n", i);
        afficherBateau(&port[i]);
    }
}