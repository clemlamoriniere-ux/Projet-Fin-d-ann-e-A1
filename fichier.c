#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "fichier.h"

void creer_fichier(planete planet){
    double masse;
    double perihelie;
    double excentriste;
    double demi_axe;
    determiner_planete(planet.nom, &masse, &perihelie, &excentriste, &demi_axe);

    trajectoire traj = new_trajectoire(365 * 50); // 365: Révolution de la Terre
    planete Earth = new_planete("Terre", masse, traj, perihelie);
    trajectoire traj_Earth = euler(Earth);
    printf("Euler termine\n");
    char* nom_planete = planet.nom;
    nom_planete = strcat(nom_planete,".json");
    FILE *fichier = fopen(nom_planete,"w");
    printf("Fichier ouvert\n");
    if (fichier == NULL){
        printf("Erreur : Impossible de creer le fichier JSON\n");
        return;
    }
    printf("Simulation en cours...\n");
    fprintf(fichier, "{\n");
    fprintf(fichier, "\"earth-euler\" : [\n");
    printf("Debut ecriture\n");
    for (int i = 0; i < 365 * 50; i++){
        point p = traj_Earth.ensemble[i];
        fprintf(fichier, "[[%e,%e,%e],[%e,%e,%e],%d]", p.r.x, p.r.y, p.r.z, p.v.x, p.v.y, p.v.z, p.t);
        if (i < 365 * 50 - 1)
            fprintf(fichier, ",\n");
    }
    fprintf(fichier, "\n]\n}");
    fclose(fichier);
    printf("Fichier 'trajectoire.json' genere avec succes !\n");
    free(traj_Earth.ensemble);
    free(traj.ensemble);
    return;
}
