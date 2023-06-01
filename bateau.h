/*
 -----------------------------------------------------------------------------------
 Nom du fichier : bateau.h
 Auteur(s)      : Leonard Klasen, Nathan Rayburn, Keya Dessasa
 Date creation  : 25.05.2023

 Description    : Ce fichier d'en-tête contient les déclarations permettant
                  d'utiliser la structure bateau.

 Remarque(s)    : -

 Compilateur    : Mingw-w64 gcc 12.2.0
 -----------------------------------------------------------------------------------
*/

#ifndef BATEAU_H
#define BATEAU_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEVISE "Euros"
#define ESPACEMENT 20
#define str(x) #x
#define xstr(s) str(s)


typedef enum {
    VOILIER, MOTEUR
} TypeBateau;
static const char *const typeBateauString[] = {
        "Voilier", "Moteur"
};

//Ce sont les sous-catégories du bateau à moteur
//AUCUNE est utilisé pour les bateaux à voile
typedef enum {
    PECHE,
    PLAISANCE,
    AUCUNE
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
typedef Bateau Port[];


#endif //BATEAU_H