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
#include "bateau_affichage.h"
#include "statistiques.h"
int main(void) {
    Bateau monaco[] = {

            // Les voiliers
            {.nomBateau = "L'ALBATROS",
                    .typeBateau = VOILIER,
                    .caracteristiqueBateau.voilier.surfaceVoile = 250},
            {.nomBateau = "MOTU",
                    .typeBateau = VOILIER,
                    .caracteristiqueBateau.voilier.surfaceVoile = 200},
            {.nomBateau = "VIRUS",
                    .typeBateau = VOILIER,
                    .caracteristiqueBateau.voilier.surfaceVoile = 65},

            // Quelques bateaux à moteurs
            {.nomBateau = "Le VAGABOND 2",
                    .typeBateau = MOTEUR,
                    .caracteristiqueBateau.moteur.puissance = 30,
                    .caracteristiqueBateau.moteur.casUtilisation = PECHE,
                    .caracteristiqueBateau.moteur.typeBateauMoteur.peche.tonnagePoisson = 12},
            {.nomBateau = "EMBUSCADE 3",
                    .typeBateau = MOTEUR,
                    .caracteristiqueBateau.moteur.puissance = 100,
                    .caracteristiqueBateau.moteur.casUtilisation = PECHE,
                    .caracteristiqueBateau.moteur.typeBateauMoteur.peche.tonnagePoisson = 20},
            {.nomBateau = "CASH-A-L'EAU",
                    .typeBateau = MOTEUR,
                    .caracteristiqueBateau.moteur.puissance = 120,
                    .caracteristiqueBateau.moteur.casUtilisation = PECHE,
                    .caracteristiqueBateau.moteur.typeBateauMoteur.peche.tonnagePoisson = 50},

            // un bateau de plaisance
            {.nomBateau = "MACALOU 2",
                    .typeBateau = MOTEUR,
                    .caracteristiqueBateau.moteur.puissance = 150,
                    .caracteristiqueBateau.moteur.casUtilisation = PLAISANCE,
                    .caracteristiqueBateau.moteur.typeBateauMoteur.plaisance = {
                            .longueur = 200,
                            .nomProprietaire = "Jean-Francois",
                    }}
    };

    afficherPort(monaco,7);
    statistiques(monaco,7);

    return 0;
}