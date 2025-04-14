#include <stdio.h>
#include <stdlib.h>
#include "armes.h"

void atout(combattant* p, Assets a) {
    switch(a) {
        case Bouclier:
            p->def += 0.1;
            p->dodge -= 0.1;
            break;
        case Epee:
            p->att += 0.1;
            p->def -= 0.1;
            break;
        case Mitraillette:
            p->crit1 += 0.1;
            p->crit2 += 0.1;
            p->pv -= 10;
            break;
        case Baton:
            p->dodge += 0.1;
            p->crit1 -= 0.1;
            p->crit2 -= 0.1;
            break;
        case Medkit:
            p->pv += 10;
            p->att -= 0.1;
            break;
        case Eclair:
            p->speed += 1;
            p->att -= 0.1;
            break;
        case None:
            break;
        default:
            printf("error : atout non reconnu \n");
            exit(1);
    }
}
