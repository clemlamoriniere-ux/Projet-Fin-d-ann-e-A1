#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "constante.h"
#include "planete.h"
#include "point.h"
#include "trajectoire.h"
#include "vector.h"

trajectoire euler(planete planet){

    vector position = new_vector(PERIHELIE_TERRE, 0, 0);
    double norme = norme(position);
    // vitesse depart
    // valeur en Y
    double vitesse_perihelie_y = sqrt((GRAVITY * MASSE_SOLEIL * (1 + EXCENTRISTE_TERRE)) / (DEMI_AXE_TERRE * (1 - EXCENTRISTE_TERRE)));
    // vitesse en vecteur
    vector vitesse = new_vector(0, vitesse_perihelie_y, 0);
    // val acc
    double acceleration_perihelie_x = -(GRAVITY * MASSE_SOLEIL) / pow(norme, 2);
    // vect acc
    vector acceleration = multiplication(position,-(GRAVITY * MASSE_SOLEIL) / pow(norme, 3));
    // pas de temps = 1 jour
    int dt = 86400;

    trajectoire traj;
    traj.ensemble = malloc(sizeof(point) * 365);
    for (int i = 0; i < 365; i++){
        vector pos_t_plus_un = addition(planet.r,multiplication(planet.v, dt));
        vector v_t_plus_un = addition(planet.v,multiplication(acceleration, dt));
        position = pos_t_plus_un;
        vitesse = v_t_plus_un;
        traj.ensemble[i] = new_point(pos_t_plus_un, v_t_plus_un, i*dt);
    }
    return traj;
}

int main()
{
}

// enlever les include inutiles dans tous les fichiers