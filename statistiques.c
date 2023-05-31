//
// Created by nathanrayburn on 31/05/2023.
//

#include "statistiques.h"
#include "bateau.h"
#include <math.h>

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
int comparerDouble(const void *a, const void *b) {
    double valeur1 = *(const double *) a;
    double valeur2 = *(const double *) b;

    if (valeur1 < valeur2) return -1;
    if (valeur1 > valeur2) return 1;
    return 0;
}


// Permet de créer un tableau contenant les taxes annuelles pour les bateau de chaque catégorie
// et d'envoyer ce tableau à la fonction mediane qui va calculer sa médiane
double medianeTaxes(const Port port, size_t nbPlaces, TypeBateau typeBateau,
                    CasUtilisation catUtilis);

double mediane(double *valeurs, size_t taille) {
    assert(valeurs);
    double valeurMediane;
    size_t millieuTableau = taille/2;
    qsort(valeurs, taille, sizeof(double), comparerDouble);
    valeurMediane = taille %2 ? valeurs[millieuTableau] : valeurs[millieuTableau] + valeurs[millieuTableau - 1];

    return valeurMediane;
}


double ecTypeTaxes(const Port port, size_t nbPlaces, TypeBateau typeBateau,
                   CasUtilisation catUtilis){
    assert(port);
    size_t nbreCategoriesBateau = 0;
    double valeurEcartMoy = 0;
    double moyenne = moyenneTaxes(port, nbPlaces, typeBateau, catUtilis);
    for (size_t i = 0; i < nbPlaces; ++i) {
        if (port[i] && appartientCatBateau(port[i], typeBateau, catUtilis)) {
            valeurEcartMoy += pow(taxeAnnuelle(port[i]) - moyenne, 2);
            ++nbreCategoriesBateau;
        }
    }
    return sqrt(valeurEcartMoy / (double) nbreCategoriesBateau);
}