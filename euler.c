#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "euler.h"
#include "constante.h"
#include "planete.h"

trajectoire euler(planete planet)
{
    /*
    Résolution de l'équation différentiel par la méthode d'Euler pour obtenir une trajectoire à convertir en JSON
    */

    double masse;
    double perihelie;
    double excentriste;
    double demi_axe;
    determiner_planete(planet.nom, &masse, &perihelie, &excentriste, &demi_axe);

    vector position = new_vector(perihelie, 0, 0); // vecteur position initial
    double distance = norme(position);             // norme du vecteur position

    // valeur initiale de la vitesse en y
    double vitesse_perihelie_y = sqrt((GRAVITY * MASSE_SOLEIL * (1 + excentriste)) / (demi_axe * (1 - excentriste)));
    // vecteur vitesse initial
    vector vitesse = new_vector(0, vitesse_perihelie_y, 0);

    // vecteur accélération
    vector acceleration = multiplication(position, -(GRAVITY * MASSE_SOLEIL) / pow(distance, 3));

    int dt = 3600 * 6; // pas de temps = 1 jour

    trajectoire traj;
    traj.ensemble = malloc(sizeof(point) * 365 * 50); // 365: Révolution de la Terre
    for (int i = 0; i < 365 * 50; i++)
    {
        vector pos_t_plus_un = addition(position, multiplication(vitesse, dt));   // pos(t) + v(t)*dt
        vector v_t_plus_un = addition(vitesse, multiplication(acceleration, dt)); // v(t) + a(t)*dt

        position = pos_t_plus_un;
        vitesse = v_t_plus_un;
        distance = norme(position);
        acceleration = multiplication(position, -(GRAVITY * MASSE_SOLEIL) / pow(distance, 3));
        traj.ensemble[i] = new_point(pos_t_plus_un, v_t_plus_un, i * dt);
    }
    return traj;
}

trajectoire euler_asymetrique(planete planet)
{
    /*
    Résolution de l'équation différentiel par la méthode d'Euler asymètrique pour obtenir une trajectoire à convertir en JSON
    */

    double masse;
    double perihelie;
    double excentriste;
    double demi_axe;
    determiner_planete(planet.nom, &masse, &perihelie, &excentriste, &demi_axe);

    vector position = new_vector(perihelie, 0, 0); // vecteur position initial
    double distance = norme(position);             // norme du vecteur position

    // valeur initiale de la vitesse en y
    double vitesse_perihelie_y = sqrt((GRAVITY * MASSE_SOLEIL * (1 + excentriste)) / (demi_axe * (1 - excentriste)));
    // vecteur vitesse initial
    vector vitesse = new_vector(0, vitesse_perihelie_y, 0);

    // vecteur accélération
    vector acceleration = multiplication(position, -(GRAVITY * MASSE_SOLEIL) / pow(distance, 3));

    int dt = 3600 * 6; // pas de temps = 1 jour

    trajectoire traj;
    traj.ensemble = malloc(sizeof(point) * 365 * 50); // 365: Révolution de la Terre
    for (int i = 0; i < 365 * 50; i++)
    {
        vector v_t_plus_un = addition(vitesse, multiplication(acceleration, dt)); // v(t) + a(t)*dt
        vector pos_t_plus_un = addition(position, multiplication(v_t_plus_un, dt));   // pos(t) + v(t)*dt

        position = pos_t_plus_un;
        vitesse = v_t_plus_un; 
        distance = norme(position);
        acceleration = multiplication(position, -(GRAVITY * MASSE_SOLEIL) / pow(distance, 3));
        traj.ensemble[i] = new_point(pos_t_plus_un, v_t_plus_un, i * dt);
    }
    return traj;
}