#ifndef PERSONNAGES_H
#define PERSONNAGES_H

typedef struct {
    char* nom;
    int pv;
    int att;
    int def;
    int speed;
    int dodge;
    int crit;
} Personnage;

extern Personnage persos[12];

#endif
