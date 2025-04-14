#ifndef COMBATTANT_H
#define COMBATTANT_H

#define PVMAX 120
#define ENNERGY 10

typedef struct {
    char* name;
    float pv;
    float pv_max;
    float def;
    float att;
    int speed;
    float dodge;
    int ennergie;

    char* crit_name1;
    float crit1;
    float crit_conso1;

    char* crit_name2;
    float crit2;
    float crit_conso2;
} Player;

// Déclaration des joueurs (vous pouvez plus tard les charger depuis un fichier)
extern Player p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12;

#endif
