#ifndef PLANETE_H
#define PLANETE_H

#include "trajectoire.h"

typedef struct planete_{
    char *nom;
    double masse;
    trajectoire traj;
    double periphelie;
} planete;

planete new_planete(char* nom1, double masse1,trajectoire traj1,double perihelie1);

#endif