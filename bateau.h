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
#ifndef BATEAU_H
#define BATEAU_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef enum {
    VOILIER, MOTEUR
} TypeBateau;
static const char *const typeBateauString[] = {
        "Voilier", "Moteur"
};

typedef enum {
    PECHE,
    PLAISANCE

} CasUtilisation;

static const char *const casUtilisationString[] = {
        "Peche", "Plaisance", "Aucune"
};

typedef struct {
    uint16_t surfaceVoile;

} Voilier;

typedef struct {
    uint8_t tonnagePoisson;
} Peche;

typedef struct {
    char *nomProprietaire;
    uint8_t longueur;
} Plaisance;

typedef union {
    Peche peche;
    Plaisance plaisance;
} TypeBateauMoteur;

typedef struct {
    uint16_t puissance;
    CasUtilisation casUtilisation;
    TypeBateauMoteur typeBateauMoteur;
} Moteur;

typedef union {
    Voilier voilier;
    Moteur moteur;
} CaracteristiqueBateau;

typedef struct {
    char *nomBateau;
    TypeBateau typeBateau;
    CaracteristiqueBateau caracteristiqueBateau;
} Bateau;

// Un port est un tableau de pointeurs vers des bateaux
typedef Bateau *Port[];

Bateau *moteurPeche(const char *nom, uint16_t puissance, uint8_t tonnePoisson);

Bateau *moteurPlaisance(const char *nom, uint16_t puissance, uint8_t longueurBateau, const char *nomPrio);

Bateau *voilier(const char *nom, uint16_t surface);

// Affichage
void afficherBateau(const Bateau *bateau);

void afficherPort(const Port port, size_t nbPlaces);

void afficherMoteur(const Moteur *moteur);

void afficherVoilier(const Voilier *voilier);

void statParCat(const Port port, size_t nbPlaces, CasUtilisation casUtilisation, TypeBateau typeBateau);

void statistiques(const Port port, size_t nbPlaces);

#endif //BATEAU_H


int comparerTaxeDesc(void *a, void *b);

bool appartientCatBateau(const Bateau *b, TypeBateau typeBateau,
                         CasUtilisation casUtilisation);