#ifndef PLANETE_H
#define PLANETE_H

#include "trajectoire.h"

typedef struct planete_{
    char *nom;
    double masse;
    trajectoire traj;
    double perihelie;
} planete;

planete new_planete(char* nom1, double masse1,trajectoire traj1,double perihelie1);
void determiner_planete(char *nom, double *masse, double *perihelie, double *excentriste, double *demi_axe);

#endif