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


void printTrajectoire(trajectoire traj, int nbPoints){
/*
Afficher une trajectoire
*/
    printf("[");
    for(int i = 0; i < nbPoints; i++){
        printf("[pos=(%e,%e,%e),vit=(%e,%e,%e),t=%d],\n", traj.ensemble[i].r.x,traj.ensemble[i].r.y,traj.ensemble[i].r.z,traj.ensemble[i].v.x,traj.ensemble[i].v.y,traj.ensemble[i].v.z, traj.ensemble[i].t);
    }
    printf("]");
}