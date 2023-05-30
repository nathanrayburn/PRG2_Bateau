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
/*
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
*/
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
/***
 * Creation nouveau bateau à moteur de pêche
 * @param nom
 * @param puissance
 * @param tonnePoisson
 * @return pointeur sur le bateau créé, NULL si erreur
 */
Bateau *moteurPeche(const char *nom, uint16_t puissance, uint8_t tonnePoisson) {
    assert(nom);
    if(puissance > 0 && tonnePoisson > 0){
        Bateau *bateau = malloc(sizeof(Bateau));
        if(bateau){
            bateau->nomBateau = nom;
            bateau->typeBateau = MOTEUR;
            bateau->caracteristiqueBateau.moteur.casUtilisation = PECHE;
            bateau->caracteristiqueBateau.moteur.puissance = puissance;
            bateau->caracteristiqueBateau.moteur.typeBateauMoteur.peche.tonnagePoisson = tonnePoisson;
            return bateau;
        }
    }
    return NULL;
}
/**
 * Creation nouveau bateau à moteur de plaisance
 * @param nom
 * @param puissance
 * @param longueurBateau
 * @param nomPrio
 * @return pointeur sur le bateau créé, NULL si erreur
 */
Bateau *moteurPlaisance(const char *nom, uint16_t puissance, uint8_t longueurBateau, const char *nomPrio) {
    assert(nom);
    if(puissance > 0 && longueurBateau > 0 && nomPrio){
        Bateau *bateau = malloc(sizeof(Bateau));
        if(bateau){
            bateau->nomBateau = nom;
            bateau->typeBateau = MOTEUR;
            bateau->caracteristiqueBateau.moteur.casUtilisation = PLAISANCE;
            bateau->caracteristiqueBateau.moteur.puissance = puissance;
            bateau->caracteristiqueBateau.moteur.typeBateauMoteur.plaisance.longueur = longueurBateau;
            bateau->caracteristiqueBateau.moteur.typeBateauMoteur.plaisance.nomProprietaire = nomPrio;
            return bateau;
        }
    }
    return NULL;
}
/**
 * Creation nouveau bateau voilier
 * @param nom
 * @param surface
 * @return pointeur sur le bateau créé, NULL si erreur
 */
Bateau *voilier(const char *nom, uint16_t surface) {
    assert(nom);
    if(surface > 0){
        Bateau *bateau = malloc(sizeof(Bateau));
        if(bateau){
            bateau->nomBateau = nom;
            bateau->typeBateau = VOILIER;
            bateau->caracteristiqueBateau.voilier.surfaceVoile = surface;
            return bateau;
        }
    }
    return NULL;
}

