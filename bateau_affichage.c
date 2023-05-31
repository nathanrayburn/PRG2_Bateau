/*
 -----------------------------------------------------------------------------------
 Nom du fichier : bateau_affichage.c
 Auteur(s)      : Leonard Klasen, Nathan Rayburn, Keya Dessasa
 Date creation  : 31.05.2023

 Description    : Ce fichier contient l'implémentation des fonctions d'affichage

 Remarque(s)    : -

 Compilateur    : Mingw-w64 gcc 12.2.0
 -----------------------------------------------------------------------------------
*/


#include "bateau_affichage.h"


void afficherVoilier(const Voilier *voilier) {
    assert(voilier);
    printf("%-" xstr(ESPACEMENT) "s: %d m^2\n", "Surface de voile", voilier->surfaceVoile);
}

void afficherMoteur(const Moteur *moteur) {
    assert(moteur);
    printf("%-" xstr(ESPACEMENT) "s: %s\n", "Cas d'utilsiation", casUtilisationString[moteur->casUtilisation]);
    printf("%-" xstr(ESPACEMENT) "s: %d\n", "Puissance", moteur->puissance);
    switch (moteur->casUtilisation) {
        case PECHE:
            printf("%-" xstr(ESPACEMENT) "s: %d\n", "Tonnage du poisson",
                   moteur->typeBateauMoteur.peche.tonnagePoisson);
            break;
        case PLAISANCE:
            printf("%-" xstr(ESPACEMENT) "s: %s\n", "Nom du proprietaire",
                   moteur->typeBateauMoteur.plaisance.nomProprietaire);
            printf("%-" xstr(ESPACEMENT) "s: %d\n", "Longueur", moteur->typeBateauMoteur.plaisance.longueur);
            break;

        case AUCUNE:
            break;
    }
}

/**
 * Affiche le nom, la catégorie et la propriété de l'attribut propre au bateau
 * @param port
 * @param nbPlaces
 * @param typeBateau
 * @param casUtilisation
 */
void afficherBateau(const Bateau *bateau, double taxe) {
    assert(bateau);

    printf("%-" xstr(ESPACEMENT) "s: %s\n", "Nom", bateau->nomBateau);
    printf("%-" xstr(ESPACEMENT) "s: %s\n", "Genre", typeBateauString[bateau->typeBateau]);
    switch (bateau->typeBateau) {
        case VOILIER:
            afficherVoilier(&bateau->caracteristiqueBateau.voilier);
            break;
        case MOTEUR:
            afficherMoteur(&bateau->caracteristiqueBateau.moteur);
            break;
    }

    printf("%-" xstr(ESPACEMENT) "s: %.2f %s\n", "Taxe annuelle", taxe, DEVISE);

}

/**
 * Affiche les informations sur tous les bateaux d'un port
 * @param port Pointeur sur le port
 * @param nbPlaces Nombre de place du port
 */
void afficherPort(const Port port, size_t nbPlaces) {
    assert(port);
    printf("Listes des bateaux du port:\n");
    TaxeCalculeeBateau *taxeCalculeeBateaux = (TaxeCalculeeBateau *) calloc(nbPlaces, sizeof(TaxeCalculeeBateau));
    calculerTaxeDescroissant(taxeCalculeeBateaux, port, nbPlaces);
    for (size_t i = 0; i < nbPlaces; ++i) {
        printf("%d)\n", i);
        TaxeCalculeeBateau stru = taxeCalculeeBateaux[i];

        printf("taxe %f ", stru.taxe);
        //afficherBateau(taxeCalculeeBateaux[i].bateau, taxeCalculeeBateaux[i].taxe);
    }
    free(taxeCalculeeBateaux);
}