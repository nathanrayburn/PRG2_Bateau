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


typedef enum {
    VOILIER, MOTEUR
} typeBateau;
static const char *const typeBateauString[] = {
        "Voilier", "Moteur"
};

typedef enum {
    PECHE,
    PLAISANCE,
    AUCUNE
} CasUtilisation;

static const char *const casUtilisationString[] = {
        "Peche", "Plaisance", "Aucune"
};

typedef struct {
    const uint16_t surfaceVoile;

} Voilier;

typedef struct {
    const uint16_t puissance;
} Moteur;

typedef union {
    Voilier voilier;
    Moteur moteur;
} CaracteristiqueBateau;

typedef struct {
    char *nomBateau;
    typeBateau typeBateau;
    CaracteristiqueBateau caracteristiqueBateau;;
} Bateau;

// Un port est un tableau de pointeurs vers des bateaux
typedef Bateau *Port[];

//
Bateau *moteur(const char *nom, uint16_t puissance);

Bateau *moteurPeche(const char *nom, uint16_t puissance, uint8_t tonnePoisson);

Bateau *moteurPlaisance(const char *nom, uint16_t puissance, uint8_t longueurBateau, const char *nomPrio);

Bateau *voilier(const char *nom, uint16_t surface);




//Fonctions Taxes
double taxeAnnuelle(const Bateau *bateau);

#endif //BATEAU_H
