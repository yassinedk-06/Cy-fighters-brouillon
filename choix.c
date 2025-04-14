#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../assets/couleurs.h"

int demanderChoixDansIntervalle(const char *texte, int min, int max, const char *couleur) {
    int choix = 0;
    char ligne[10];

    do {
        printf("%s%s (%d à %d) : " RESET, couleur, texte, min, max);
        if (fgets(ligne, sizeof(ligne), stdin)) {
            if (sscanf(ligne, "%d", &choix) == 1 && choix >= min && choix <= max) {
                return choix;
            }
        }
        printf(ROUGE "Choix incorrect, rechoisis\n" RESET);
    } while (1);
}

int demanderChoix(const char *texte) {
    int choix = 0;
    char ligne[10];

    do {
        printf(JAUNE "%s (1 ou 2) : " RESET, texte);
        if (fgets(ligne, sizeof(ligne), stdin)) {
            if (sscanf(ligne, "%d", &choix) == 1 && (choix == 1 || choix == 2)) {
                return choix;
            }
        }
        printf(ROUGE "Choix incorrect, rechoisis\n" RESET);
    } while (1);
}
