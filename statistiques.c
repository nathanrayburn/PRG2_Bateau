
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
// Somme des taxes pour un certain type de bateau
double sommeTaxes(const Port port, size_t nbPlaces, TypeBateau typeBateau,
                  CasUtilisation catUtilis){

    assert(port);
    double somme = 0;
    for (size_t i = 0; i < nbPlaces; ++i) {
        if (&port[i] && appartientCatBateau(&port[i], typeBateau, catUtilis)) {
            somme += taxeAnnuelle(&port[i]);
        }
    }
    return somme;
}

/**
 *
 * @param port
 * @param nbPlaces
 * @param typeBateau
 * @param catUtilis
 * @return
 */
double moyenneTaxes(const Port port, size_t nbPlaces, TypeBateau typeBateau,
                    CasUtilisation catUtilis) {
    assert(port);
    size_t nbrBateauParCat = 0;
    double somme = 0;
    for(size_t i = 0; i < nbPlaces; ++i) {
        if(&port[i] && appartientCatBateau(&port[i], typeBateau, catUtilis)) {
            ++nbrBateauParCat;
            somme += taxeAnnuelle(&port[i]);
        }
    }
    return somme / nbrBateauParCat;
}
/**
 * fonction utilisée par qsort pour comparer les doubles et les trier
 * source: https://en.cppreference.com/w/c/algorithm/qsort
 * @param a
 * @param b
 * @return
 */
int comparerDouble(const void *a, const void *b) {
    double valeur1 = *(const double *) a;
    double valeur2 = *(const double *) b;

    if (valeur1 < valeur2) return -1;
    if (valeur1 > valeur2) return 1;
    return 0;
}

/**
 * Calcule la médiane du tableau de valeurs passé en paramètre
 * Le tableau original est trié et modifié
 * @param valeurs
 * @param taille
 * @return double
 */
double mediane(double *valeurs, size_t taille) {
    assert(valeurs);
    qsort(valeurs, taille, sizeof(double), comparerDouble);
    return taille ? (valeurs[(taille - 1) / 2] + valeurs[taille / 2]) / 2.0 : 0;
}

/**
 * Permet de calculer l'ecart type
 * @param port
 * @param nbPlaces
 * @param typeBateau
 * @param casUtilisation
 * @return double
 */
double ecTypeTaxes(const Port port, size_t nbPlaces, TypeBateau typeBateau,
                   CasUtilisation casUtilisation){
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
/**
 * Fonction qui retourne si le bateau appartient à un cas d'utilisation
 * @param b
 * @param typeBateau
 * @param casUtilisation
 * @return
 */
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
/**
 * Afficher les statistiques pour les 3 catégories
 * @param port
 * @param nbPlaces
 */
void statistiques(const Port port, size_t nbPlaces) {
    assert(port);
    stat(port, nbPlaces, VOILIER, AUCUNE);
    stat(port, nbPlaces, MOTEUR, PECHE);
    stat(port, nbPlaces, MOTEUR, PLAISANCE);
}
/**
 * Permet d'afficher les statistiques d'une catégorie
 * @param port
 * @param nbPlaces
 * @param typeBateau
 * @param casUtilisation
 */
void stat(const Port port, size_t nbPlaces, TypeBateau typeBateau,
          CasUtilisation casUtilisation) {
    assert(port);
    printf("\nStatistiques\n\n");
    printf("%-20s : %s %s\n",
            "Categorie", typeBateauString[typeBateau], casUtilisationString[casUtilisation]);

    printf("%-20s : %.2f %s\n",
            MESS_TAXE_SOMME, sommeTaxes(port, nbPlaces, typeBateau, casUtilisation),
            DEVISE);

    printf("%-20s : %.2f %s\n",
            MESS_TAXE_MOYENNE, moyenneTaxes(port, nbPlaces, typeBateau, casUtilisation),
            DEVISE);

    printf("%-20s : %.2f %s\n",
            MESS_TAXE_MEDIANE, medianeTaxes(port, nbPlaces, typeBateau, casUtilisation),
            DEVISE);

    printf("%-20s : %.2f %s\n",
            MESS_TAXE_ECTYPE, ecTypeTaxes(port, nbPlaces, typeBateau, casUtilisation),
            DEVISE);
}
/**
 * Calculer la mediane des taxes
 * @param port
 * @param nbPlaces
 * @param typeBateau
 * @param casUtilisation
 * @return double
 */
double medianeTaxes(const Bateau *port, size_t nbPlaces, TypeBateau typeBateau, CasUtilisation casUtilisation) {
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
/**
 * Retour nombre de bateau de la categorie
 * @param port
 * @param nbPlaces
 * @param typeBateau
 * @param casUtilisation
 * @return size_t
 */
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