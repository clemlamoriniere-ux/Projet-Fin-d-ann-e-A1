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

    /*
    Résolution de l'équation différentiel par la méthode d'Euler pour obtenir une trajectoire à convertir en JSON
    */
    vector position = new_vector(PERIHELIE_TERRE, 0, 0); // vecteur position initial
    double distance = norme(position);                   // norme du vecteur position

    // valeur initiale de la vitesse en y
    double vitesse_perihelie_y = sqrt((GRAVITY * MASSE_SOLEIL * (1 + EXCENTRISTE_TERRE)) / (DEMI_AXE_TERRE * (1 - EXCENTRISTE_TERRE)));
    // vecteur vitesse initial
    vector vitesse = new_vector(0, vitesse_perihelie_y, 0);

    // vecteur accélération
    vector acceleration = multiplication(position, -(GRAVITY * MASSE_SOLEIL) / pow(distance, 3));

    int dt = 86400; // pas de temps = 1 jour

    trajectoire traj;
    traj.ensemble = malloc(sizeof(point) * 365); // 365: Révolution de la Terre
    for (int i = 0; i < 365; i++)
    {
        vector v_t_plus_un = addition(vitesse, multiplication(acceleration, dt));
        vector pos_t_plus_un = addition(position, multiplication(v_t_plus_un, dt));
        position = pos_t_plus_un;                                                              // nouvelle position
        vitesse = v_t_plus_un;                                                                 // nouvelle vitesse
        distance = norme(position);                                                            // nouvelle norme
        acceleration = multiplication(position, -(GRAVITY * MASSE_SOLEIL) / pow(distance, 3)); // nouvelle accélération
        traj.ensemble[i] = new_point(pos_t_plus_un, v_t_plus_un, i * dt);                      // ajout d'un point pour former la trajectoire
    }
    return traj;
}

int main()
{
    vectorTest();

    trajectoire traj = new_trajectoire(365); // 365: Révolution de la Terre
    planete Earth = new_planete("Terre", MASSE_TERRE, traj, PERIHELIE_TERRE);
    trajectoire traj_Earth = euler(Earth);
    printf("Euler termine\n");
    FILE *fichier = fopen("trajectoire.json", "w");
    printf("Fichier ouvert\n");
    if (fichier == NULL)
    {
        printf("Erreur : Impossible de creer le fichier JSON\n");
        return 1;
    }
    printf("Simulation en cours...\n");
    fprintf(fichier, "{\n");
    fprintf(fichier, "\"earth-euler\" : [\n");
    printf("Debut ecriture\n");
    for (int i = 0; i < 365; i++)
    {
        point p = traj_Earth.ensemble[i];
        fprintf(fichier, "[[%e,%e,%e],[%e,%e,%e],%d]", p.r.x, p.r.y, p.r.z, p.v.x, p.v.y, p.v.z, p.t);
        if (i < 364)
            fprintf(fichier, ",\n");
    }
    fprintf(fichier, "\n]\n}");
    fclose(fichier);
    printf("Fichier 'trajectoire.json' genere avec succes !\n");
    free(traj_Earth.ensemble);
    free(traj.ensemble);
    return 0;
}