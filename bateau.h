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
typedef enum {
    VOILIER, MOTEUR
} typeBateau;
static const char *const typeBateauString[] = {
        "Voilier", "Moteur"
};

typedef enum {
    PECHE, PLAISANCE, AUCUNE
} CasUtilisation;
static const char *const casUtilisationString[] = {
        "Peche", "Plaisance", "Aucune"
};
typedef struct Voilier {

};
typedef struct Moteur {

};
typedef struct CaracteristiqueBateau {
    Voilier voilier;
    Moteur moteur;
};
typedef struct {
    char *nomBateau;
    typeBateau typeBateau;
    struct CaracteristiqueBateau caracteristiqueBateau;;
} Bateau;

#endif //BATEAU_H
