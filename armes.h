#ifndef ARMES_H
#define ARMES_H

#include "combattant.h"

typedef enum {Bouclier, Epee, Mitraillette, Baton, Medkit, Eclair, None} Assets;

void atout(Player* p, Assets a);

#endif
