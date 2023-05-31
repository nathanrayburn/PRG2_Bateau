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
