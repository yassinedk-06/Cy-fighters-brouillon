#include <stdio.h>
#include <stdlib.h>
#define ROUGE   "\033[1;31m"
#define VERT    "\033[1;32m"
#define JAUNE   "\033[1;33m"
#define BLEU    "\033[1;36m"
#define RESET   "\033[0m"

void afficherTitre() {
    system("clear"); 
    printf(ROUGE);
    printf("  _____ _            _        ______ _       _     _            \n");
    printf(" / ____| |          | |      |  ____(_)     | |   | |           \n");
    printf("| (___ | |_ ___  ___| |_     | |__   _  __ _| |__ | |_ ___ _ __ \n");
    printf(" \\___ \\| __/ _ \\/ __| __|    |  __| | |/ _` | '_ \\| __/ _ \\ '__|\n");
    printf(" ____) | ||  __/ (__| |_     | |    | | (_| | | | | ||  __/ |   \n");
    printf("|_____/ \\__\\___|\\___|\\__|    |_|    |_|\\__, |_| |_|\\__\\___|_|   \n");
    printf("                                         __/ |                  \n");
    printf("                                        |___/                   \n");
    printf(RESET);
    printf("\nAppuyer sur Enter pour ouvrir le jeu");
    getchar();
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
        printf(ROUGE "Choix incorect, rechoisie\n" RESET);
    } while (1);
}

void afficherMenu() {
    system("clear");

    printf(BLEU "** MODE DE JEU **\n" RESET);
    printf("1. Joueur vs Joueur (PVP)\n");
    printf("2. Joueur vs Ordinateur (PVC)\n\n");

    int mode = demanderChoix("Choisis ton mode");

    printf(BLEU "\n** TAILLE DE L'EQUIPE **\n" RESET);
    printf("1. 2 contre 2\n");
    printf("2. 3 contre 3\n\n");

    int equipe = demanderChoix("Choisis la taille de ton equipe");

    printf(VERT "\nTu as choisi : %s\n", (mode == 1) ? "PVP" : "PVC");
    printf("Taille : %s\n\n" RESET, (equipe == 1) ? "2v2" : "3v3");
}

int main() {
    afficherTitre();
    afficherMenu();
return 0;
}
