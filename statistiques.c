/*
 -----------------------------------------------------------------------------------
 Nom du fichier : statistiques.c
 Auteur(s)      : Leonard Klasen, Nathan Rayburn, Keya Dessasa
 Date creation  : 25.05.2023

 Description    : Ce fichier contient l'implémentation des fonctions
                  calculant les différentes statistiques d'un port donné.

 Remarque(s)    : -

 Compilateur    : Mingw-w64 gcc 12.2.0
 -----------------------------------------------------------------------------------
*/

#include "statistiques.h"
#include "bateau.h"
#include "taxes.h"
#include <math.h>
#include <stdlib.h>


// Messages utilisateurs
#define MAUVAISE_ALLOC "Mauvaise allocation"
#define MESS_TAXE_SOMME "Somme taxes"
#define MESS_TAXE_MOYENNE "Moyenne taxes"
#define MESS_TAXE_MEDIANE "Mediane taxes"
#define MESS_TAXE_ECTYPE "Ecart-type taxes"
#define ERR_CREATION_TABLEAU "Erreur creation tableau"


double sommeTaxes(const Port port, size_t nbPlaces, TypeBateau typeBateau,
                  CasUtilisation casUtilisation) {

    assert(port);
    double somme = 0;
    for (size_t i = 0; i < nbPlaces; ++i) {
        if (&port[i] && appartientCatBateau(&port[i], typeBateau, casUtilisation)) {
            somme += taxeAnnuelle(&port[i]);
        }
    }
    return somme;
}


double moyenneTaxes(const Port port, size_t nbPlaces, TypeBateau typeBateau,
                    CasUtilisation casUtilisation) {
    assert(port);
    size_t nbrBateauParCat = 0;
    double somme = 0;
    for (size_t i = 0; i < nbPlaces; ++i) {
        if (&port[i] && appartientCatBateau(&port[i], typeBateau, casUtilisation)) {
            ++nbrBateauParCat;
            somme += taxeAnnuelle(&port[i]);
        }
    }
    return somme / (double) nbrBateauParCat;
}


int comparerDouble(const void *a, const void *b) {
    double valeur1 = *(const double *) a;
    double valeur2 = *(const double *) b;

    if (valeur1 < valeur2) return -1;
    if (valeur1 > valeur2) return 1;
    return 0;
}


double mediane(double *valeurs, size_t taille) {
    assert(valeurs);
    qsort(valeurs, taille, sizeof(double), comparerDouble);
    return taille ? (valeurs[(taille - 1) / 2] + valeurs[taille / 2]) / 2.0 : 0;
}


double ecTypeTaxes(const Port port, size_t nbPlaces, TypeBateau typeBateau,
                   CasUtilisation casUtilisation) {
    assert(port);
    size_t nbBateauxCat = 0;
    double sommeEcartMoy = 0;
    double moyenne = moyenneTaxes(port, nbPlaces, typeBateau, casUtilisation);

    for (size_t i = 0; i < nbPlaces; ++i) {
        if (&port[i] && appartientCatBateau(&port[i], typeBateau, casUtilisation)) {
            sommeEcartMoy += pow(taxeAnnuelle(&port[i]) - moyenne, 2);
            ++nbBateauxCat;
        }
    }
    return sqrt(sommeEcartMoy / (double) nbBateauxCat);
}

bool appartientCatBateau(const Bateau* b, TypeBateau typeBateau, CasUtilisation casUtilisation) {
    assert(b);

    return (typeBateau == VOILIER) ? (b->typeBateau == VOILIER)
                                   : (typeBateau == MOTEUR) ?
   (b->typeBateau == MOTEUR && b->caracteristiqueBateau.moteur.casUtilisation == casUtilisation): false;
}

void statistiques(const Port port, size_t nbPlaces) {
    assert(port);
    stat(port, nbPlaces, VOILIER, AUCUNE);
    stat(port, nbPlaces, MOTEUR, PECHE);
    stat(port, nbPlaces, MOTEUR, PLAISANCE);
}


void stat(const Port port, size_t nbPlaces, TypeBateau typeBateau,
          CasUtilisation casUtilisation) {
    assert(port);
    printf("\nStatistiques\n\n");
    printf("%-" xstr(ESPACEMENT) "s: %s %s\n", "Categorie ", typeBateauString[typeBateau],
           casUtilisationString[casUtilisation]);

    printf("%-" xstr(ESPACEMENT) "s: %0.2f %s\n",
           MESS_TAXE_SOMME, sommeTaxes(port, nbPlaces, typeBateau, casUtilisation),
           DEVISE);

    printf("%-" xstr(ESPACEMENT) "s: %0.2f %s\n",
           MESS_TAXE_MOYENNE, moyenneTaxes(port, nbPlaces, typeBateau, casUtilisation),
           DEVISE);

    printf("%-" xstr(ESPACEMENT) "s: %0.2f %s\n",
           MESS_TAXE_MEDIANE, medianeTaxes(port, nbPlaces, typeBateau, casUtilisation),
           DEVISE);

    printf("%-" xstr(ESPACEMENT) "s: %0.2f %s\n",
           MESS_TAXE_ECTYPE, ecTypeTaxes(port, nbPlaces, typeBateau, casUtilisation),
           DEVISE);
}


double medianeTaxes(const Bateau *port, size_t nbPlaces, TypeBateau typeBateau,
                    CasUtilisation casUtilisation) {
    assert(port);
    size_t nbBateauxCat = nbBateauxCriteres(port, nbPlaces, typeBateau, casUtilisation);
    double *taxes = (double *) malloc(nbBateauxCat * sizeof(double));

    // affiche un message d'erreur si mauvaise allocation
    if (!taxes) {
        fprintf(stderr, MAUVAISE_ALLOC ": " ERR_CREATION_TABLEAU "\n");
        return 0;
    }

    for (size_t i = 0, j = 0; i < nbPlaces; ++i) {
        if (&port[i] && appartientCatBateau(&port[i], typeBateau, casUtilisation)) {
            taxes[j++] = taxeAnnuelle(&port[i]);
        }
    }

    double med = mediane(taxes, nbBateauxCat);

    free(taxes);

    return med;
}


size_t nbBateauxCriteres(const Port port, size_t nbPlaces, TypeBateau typeBateau,
                         CasUtilisation casUtilisation) {
    assert(port);
    size_t nbBateauxCat = 0;

    for (size_t i = 0; i < nbPlaces; ++i) {
        if (&port[i] && appartientCatBateau(&port[i], typeBateau, casUtilisation)) {
            ++nbBateauxCat;
        }
    }
    return nbBateauxCat;
}