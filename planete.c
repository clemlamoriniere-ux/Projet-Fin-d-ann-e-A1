#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "constante.h"
#include "planete.h"
#include "point.h"
#include "trajectoire.h"
#include "vector.h"

planete new_planete(char* nom1, double masse1,trajectoire traj1,double periphelie1){
    planete planet;
    planet.nom = nom1;
    planet.masse = masse1;
    planet.traj = traj1;
    planet.perihelie = perihelie1;
    return planet;
}

int main(){
}