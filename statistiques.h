//
// Created by nathanrayburn on 31/05/2023.
//

#ifndef PRG2_BATEAU_STATISTIQUES_H
#define PRG2_BATEAU_STATISTIQUES_H

#endif //PRG2_BATEAU_STATISTIQUES_H

#include "bateau.h"
#include "taxes.h"
#include <assert.h>

double sommeTaxes(const Port port, size_t nbPlaces, TypeBateau typeBateau,
                  CasUtilisation catUtilis);

double moyenneTaxes(const Port port, size_t nbPlaces, TypeBateau typeBateau,
                    CasUtilisation catUtilis);


double medianeTaxes(const Port port, size_t nbPlaces, TypeBateau typeBateau,
                    CasUtilisation catUtilis);

double mediane(double *valeurs, size_t taille);

double ecTypeTaxes(const Port port, size_t nbPlaces, TypeBateau typeBateau,
                   CasUtilisation catUtilis);