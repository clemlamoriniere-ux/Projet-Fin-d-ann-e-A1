#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "trajectoire.h"

trajectoire new_trajectoire(int nbPoints){
/*
Créer une trajectoire
*/
    trajectoire traj;
    traj.ensemble = malloc(sizeof(point) * nbPoints);
    return traj;
}