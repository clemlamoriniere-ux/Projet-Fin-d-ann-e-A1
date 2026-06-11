#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "constante.h"
#include "planete.h"
#include "point.h"
#include "trajectoire.h"
#include "vector.h"

int main()
{
}

trajectoire euler(planete planet)
{
    double x = PERIHELIE_TERRE;
    vector position = new_vector(x, 0, 0);
    // vitesse depart

    // valeur en Y
    double vitesse_perihelie_y = sqrt(9.81 * terre.masse_soleil * (1 + terre.excentricite)) / sqrt(terre.demi_axe(1 - terre.excentricite));
    // vitesse en vecteur
    vector vitesse = new_vector(0, vitesse_perihelie_y, 0)
        // val acc
        double acceleration_perihelie_x = -(9.81 * terre.masse_soleil) / pow(x, 2);
    // vect acc
    vector acceleration = new_vector(acceleration_perihelie_x, 0, 0);
    // pas de temps = 1 jour
    int dt = 86400;

    trajectoire traj;
    traj->ensemble = malloc(sizeof(vector) * 365);
    for (int i = 0; i < 365; i++)
    {
        double x_t_plus_un = planet.r.x + planet.v.x * dt;
        double vx_t_plus_un = planet.v.x + acceleration_perihelie_x * dt;
        traj->ensemble[i] = (x_t_plus_un, vx_t_plus_un, i);
    }
    return traj;
}
int main()
{
}
