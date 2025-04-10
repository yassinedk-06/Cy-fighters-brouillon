#include <stdio.h>
#include <stdlib.h>
#include "test.h"

#define ROUGE   "\033[1;31m"
#define VERT    "\033[1;32m"
#define JAUNE   "\033[1;33m"
#define BLEU    "\033[1;36m"
#define RESET   "\033[0m"

typedef struct {
    char* nom;
    int pv;
    int att;
    int def;
    int speed;
    int dodge;
    int crit;
} Personnage;

Personnage persos[12] = {
    {"Luffy", 2, 4, 3, 2, 4, 4},
    {"Sanji", 1, 5, 4, 3, 2, 2},
    {"Zoro", 3, 4, 1, 4, 3, 1},
    {"Ace", 4, 2, 3, 1, 5, 2},
    {"Brook", 2, 2, 4, 4, 3, 2},
    {"Ussop", 3, 2, 3, 3, 4, 1},
    {"Do Flamingo", 1, 2, 4, 5, 3, 2},
    {"Big Mom", 3, 3, 3, 1, 5, 3},
    {"Katakuri", 3, 5, 4, 1, 2, 3},
    {"Black Beard", 3, 4, 1, 4, 3, 4},
    {"Crocodile", 1, 1, 5, 5, 3, 2},
    {"Kaido", 4, 5, 3, 4, 2, 4}
};

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
        printf(ROUGE "Choix incorrect, rechoisis\n" RESET);
    } while (1);
}

void afficherMenu() {
    system("clear");

    printf(BLEU "╔══════════════════════════════════════╗\n");
    printf("║          🌟 MODE DE JEU 🌟           ║\n");
    printf("╚══════════════════════════════════════╝\n" RESET);
    printf(" 1. 🎮 Joueur vs Joueur (PVP)\n");
    printf(" 2. 🤖 Joueur vs Ordinateur (PVC)\n\n");

    int mode = demanderChoix("👉 Choisis ton mode");

    printf(BLEU "\n╔══════════════════════════════════════╗\n");
    printf("║       🛡️  TAILLE DE L'ÉQUIPE 🛡️        ║\n");
    printf("╚══════════════════════════════════════╝\n" RESET);
    printf(" 1. 👥 2 contre 2\n");
    printf(" 2. 👥 3 contre 3\n\n");

    int equipe = demanderChoix("👉 Choisis la taille de ton équipe");

    printf(VERT "\n✅ Tu as choisi : %s\n", (mode == 1) ? "PVP" : "PVC");
    printf("👥 Taille : %s\n\n" RESET, (equipe == 1) ? "2v2" : "3v3");
}

// === NOUVEAU CODE POUR AFFICHAGE DES PERSOS ===

void afficherBarre(int valeur) {
    for (int i = 0; i < valeur; i++) {
        printf("🟩");
    }
    printf("\n");
}

void afficherPersonnage(int x) {
    Personnage p = persos[x];

    printf(BLEU "╔════════════════════╗\n");
    printf("║ %-18s ║\n", p.nom);
    printf("╚════════════════════╝\n" RESET);

    printf("PV     : "); afficherBarre(p.pv);
    printf("Att    : "); afficherBarre(p.att);
    printf("Def    : "); afficherBarre(p.def);
    printf("Speed  : "); afficherBarre(p.speed);
    printf("Dodge  : "); afficherBarre(p.dodge);
    printf("Crit   : "); afficherBarre(p.crit);
    printf("\n");
}

void afficherTousLesPersos() {
    printf(BLEU "╔══════════════════════════════════════╗\n");
    printf("║       👥 PERSONNAGES DISPONIBLES 👥    ║\n");
    printf("╚══════════════════════════════════════╝\n\n" RESET);

    for (int i = 0; i < 12; i++) {
        afficherPersonnage(i);
    }

    printf("Appuie sur Entrée pour continuer...");
    getchar();
}

int main() {
    afficherTitre();
    afficherMenu();
    afficherTousLesPersos();
    return 0;
}
