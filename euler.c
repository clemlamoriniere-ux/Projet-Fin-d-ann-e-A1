#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "euler.h"
#include "constante.h"

void determiner_planete(char *nom, double *masse, double *perihelie, double *excentriste, double *demi_axe){
    /*
    Définir les valeurs selon la planète
    */
    int decalage = 'a' - 'A';
    int longueur = strlen(nom);
    char *nom_p = malloc(sizeof(char) * longueur);
    for (int i = 0; i < longueur - 1; i++)
    {
        if (nom[i] < 'a')
            nom_p[i] = nom[i] + decalage;
        else
        {
            nom_p[i] = nom[i];
        }
    }
    if (strcmp(nom_p, "terre") == 0)
    {
        *masse = MASSE_TERRE;
        *perihelie = PERIHELIE_TERRE;
        *excentriste = EXCENTRISTE_TERRE;
        *demi_axe = DEMI_AXE_TERRE;
    }
    else if (strcmp(nom_p, "mars") == 0)
    {
        *masse = MASSE_MARS;
        *perihelie = PERIHELIE_MARS;
        *excentriste = EXCENTRISTE_MARS;
        *demi_axe = DEMI_AXE_MARS;
    }
    else if (strcmp(nom_p, "jupiter") == 0)
    {
        *masse = MASSE_JUPITER;
        *perihelie = PERIHELIE_JUPITER;
        *excentriste = EXCENTRISTE_JUPITER;
        *demi_axe = DEMI_AXE_JUPITER;
    }
    else if (strcmp(nom_p, "saturne") == 0)
    {
        *masse = MASSE_SATURNE;
        *perihelie = PERIHELIE_SATURNE;
        *excentriste = EXCENTRISTE_SATURNE;
        *demi_axe = DEMI_AXE_SATURNE;
    }
    free(nom_p);
}

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
        vector pos_t_plus_un = addition(position, multiplication(vitesse, dt));   // pos(t) + v(t)*dt

        position = pos_t_plus_un;
        vitesse = v_t_plus_un;
        distance = norme(position);
        acceleration = multiplication(position, -(GRAVITY * MASSE_SOLEIL) / pow(distance, 3));
        traj.ensemble[i] = new_point(pos_t_plus_un, v_t_plus_un, i * dt);
    }
    return traj;
}