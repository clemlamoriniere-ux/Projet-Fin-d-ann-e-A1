#ifndef TRAJECTOIRE_H
#define TRAJECTOIRE_H

#include "point.h"

typedef struct trajectoire_{
    point *ensemble;
} trajectoire;

trajectoire new_trajectoire(int nbPoints);
void printTrajectoire(trajectoire traj, int nbPoints);

#endif