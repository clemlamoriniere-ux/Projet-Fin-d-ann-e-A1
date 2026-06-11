#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "planete.h"

planete new_planete(char* nom1, double masse1,trajectoire traj1,double perihelie1){
/*
créer une nouvelle planète
*/
    planete planet;
    planet.nom = nom1;
    planet.masse = masse1;
    planet.traj = traj1;
    planet.perihelie = perihelie1;
    return planet;
}