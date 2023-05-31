//
// Created by nathanrayburn on 31/05/2023.
//

#include "port.h"
#include "taxes.h"

int comparerTaxe(const void *a, const void *b) {

}

void afficherBateauxTaxeDesc(const Bateau *port, size_t taille) {
    TaxeCalc *calculations = (TaxeCalc *) calloc(taille, sizeof(TaxeCalc)  );
    for (size_t i = 0; i < taille; i++) {
        calculations[i].taxe = taxeAnnuelle(&port[i]);
        calculations[i].bateau = &port[i];
    }
    qsort(calculations, taille, sizeof(TaxeCalc), comparerTaxeDesc);
}