//
// Created by nathanrayburn on 31/05/2023.
//

#include "port.h"
#include "taxes.h"
#include "bateau_affichage.h"
int compTaxeDescendant(const void *a, const void *b) {
    return (int) ((*(TaxeCalc*) b).taxe - (*(TaxeCalc*) a).taxe);
}

void afficherBateauxTaxeDesc(const Bateau *port, size_t taille) {

    TaxeCalc *calculations = (TaxeCalc *) calloc(taille, sizeof(TaxeCalc)  );

    for (size_t i = 0; i < taille; i++) {
        calculations[i].taxe = taxeAnnuelle(&port[i]);
        calculations[i].bateau = &port[i];
    }

    qsort(calculations, taille, sizeof(TaxeCalc), compTaxeDescendant);
}