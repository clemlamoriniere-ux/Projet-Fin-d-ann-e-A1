#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "constante.h"
#include "planete.h"
#include "point.h"
#include "trajectoire.h"
#include "vector.h"

int main(){
}

trajectoire euler(point p){
    // position  depart:
    //  valeur en x

    // vecteur position

    // vitesse depart
    // valeur en Y
    double vitesse_perihelie = sqrt(9.81 * terre.masse_soleil * (1 + terre.excentricite)) / sqrt(terre.demi_axe(1 - terre.excentricite));
    // vitesse en vecteur

    // val acc
    double acceleration_perihelie = (9.81 * terre.masse_soleil) // /x^2;

        // vect acc

        // pas de temps
        int dt = 86400;

    trajectoire traj;
    traj->ensemble = malloc(sizeof(vector) * 365);
    for (int i = 0; i < 365; i++)
    {
        double x_t_plus_un = point.r.x + point.v.x * dt;
        maj acc
            maj pos r
                traj->ensemble[i] = (x_t_plus_un, vx + 1, i);
    }
    return traj;
}

int main(){
}