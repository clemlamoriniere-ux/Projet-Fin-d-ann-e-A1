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
    planete planet1 = new_planete(planet.nom, masse, traj, perihelie);
    trajectoire traj_p = euler(planet1);
    printf("Euler termine\n");
    char nom_planete[100];
    strcpy(nom_planete, planet.nom);
    strcat(nom_planete, ".json");
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
        point p = traj_p.ensemble[i];
        fprintf(fichier, "[[%e,%e,%e],[%e,%e,%e],%d]", p.r.x, p.r.y, p.r.z, p.v.x, p.v.y, p.v.z, p.t);
        if (i < 365 * 50 - 1)
            fprintf(fichier, ",\n");
    }
    fprintf(fichier, "\n]\n}");
    fclose(fichier);
    printf("Fichier 'trajectoire.json' genere avec succes !\n");

    trajectoire traj_p1 = euler_asymetrique(planet1);
    printf("Euler termine\n");
    char nom_planete1[100];
    strcpy(nom_planete1, planet.nom);
    strcat(nom_planete1, "_asym.json");
    FILE *fichier1 = fopen(nom_planete1,"w");
    printf("Fichier ouvert\n");
    if (fichier == NULL){
        printf("Erreur : Impossible de creer le fichier JSON\n");
        return;
    }
    printf("Simulation en cours...\n");
    fprintf(fichier1, "{\n");
    fprintf(fichier1, "\"earth-euler\" : [\n");
    printf("Debut ecriture\n");
    for (int i = 0; i < 365 * 50; i++){
        point p = traj_p1.ensemble[i];
        fprintf(fichier1, "[[%e,%e,%e],[%e,%e,%e],%d]", p.r.x, p.r.y, p.r.z, p.v.x, p.v.y, p.v.z, p.t);
        if (i < 365 * 50 - 1)
            fprintf(fichier1, ",\n");
    }
    fprintf(fichier1, "\n]\n}");
    fclose(fichier1);
    printf("Fichier 'trajectoire.json' genere avec succes !\n");

    free(traj_p.ensemble);
    free(traj.ensemble);
    return;
}
