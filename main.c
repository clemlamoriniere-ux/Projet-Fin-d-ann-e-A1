#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "constante.h"
#include "planete.h"
#include "point.h"
#include "trajectoire.h"
#include "vector.h"

trajectoire euler(planete planet)
{
    double x = PERIHELIE_TERRE;
    vector position = new_vector(x, 0, 0);
    // vitesse depart

    // valeur en Y
    double vitesse_perihelie_y = sqrt(GRAVITY * MASSE_SOLEIL * (1 + EXCENTRISTE_TERRE)) / sqrt(DEMI_AXE_TERRE(1 - EXCENTRISTE_TERRE));
    // vitesse en vecteur
    vector vitesse = new_vector(0, vitesse_perihelie_y, 0);
    // val acc
    double acceleration_perihelie_x = -(GRAVITY * MASSE_SOLEIL) / pow(x, 2);
    // vect acc
    vector acceleration = new_vector(acceleration_perihelie_x, 0, 0);
    // pas de temps = 1 jour
    int dt = 86400;

    trajectoire traj;
    traj->ensemble = malloc(sizeof(vector) * 365);
    for (int i = 0; i < 365; i++){
        vector pos_t_plus_un = new_vector(addition(planet.r.x , multiplication(planet.v.x , dt)),addition(planet.r.y,multiplication(vitesse_perihelie_y,dt)),0);
        vector v_t_plus_un = new_vector(addition(planet.v.x , multiplication(acceleration_perihelie_x , dt)),addition(planet.v.y,multiplication(0,dt)),0);
        traj.ensemble[i] = {pos_t_plus_un, v_t_plus_un, i};
    }
    return traj;
}

int main()
{
}

// enlever les include inutiles dans tous les fichiers