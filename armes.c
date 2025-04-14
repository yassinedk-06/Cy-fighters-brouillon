#include <stdio.h>
#include <stdlib.h>
#include "armes.h"

void choix_assets(int equipe[], int nbr_joueur) {
    int arme  = 0;
    for (int i = 0; i <= nbr_joueur; i++) {
        
        arme  = demanderChoixDansIntervalle("choisir arme : " , 0,6 , VERT);
        Personnage *p = &persos[equipe[i] - 1]; // récupérer le pointeur vers le personnage
        atout(p, arme);                        // appliquer l'atout directement
        afficherPersonnage(equipe[i] - 1);     // afficher les stats mises à jour
        
        // METRE A JOUR LA STRUCT PLAYER AVEC L AUTRE FONCTION ATOUT ...
    }
}

void choix_assets_E(int equipe1[],int equipe2[], int nbr_joueur ) {
    afficher_stats();
    printf("Au tour de l equipe 1:  \n");
    choix_assets(equipe1 , nbr_joueur);
    
    printf("\n Appuie sur Entrée pour continuer... \n");
    while (getchar() != '\n');
    
    afficher_stats();
    printf("Au tour de l equipe 2:  \n");
    choix_assets(equipe2 , nbr_joueur);
    
    
    
}

void atout(Personnage *p, int a) {
    switch (a) {
        case 1: p->def++; p->dodge--; break;
        case 2: p->att++; p->def--; break;
        case 3: p->crit++; p->pv--; break;
        case 4: p->dodge++; p->crit--; break;
        case 5: p->pv++; p->att--; break;
        case 6: p->speed++; p->att--; break;
        case 0: break;
        default:
            printf("Erreur : atout non reconnu\n");
            exit(1);
    }
}
