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

int main(void)
{
    Port monaco = {
            //Déclaration des bateaux dans le port de Monaco
            voilier("nom", 200),
            moteurPlaisance("La dune", 500, 22, "Philippe K."),
            moteurPeche("test", 600, 12),

    };

    // afficher le / les tableaux nécessaires
    afficherPort(monaco, sizeof(monaco) / sizeof(Bateau *));
	return 0;
}