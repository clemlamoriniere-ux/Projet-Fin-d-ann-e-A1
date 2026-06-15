#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "fichier.h"
#include "euler.h"
#include "planete.h"
#include "trajectoire.h"
#include "constante.h"

void creer_fichier(planete planet){
/*
Créer des fichiers JSON en fonction de la planète souhaitée
*/

    //déterminer une planète
    double masse;
    double perihelie;
    double excentriste;
    double demi_axe;
    determiner_planete(planet.nom, &masse, &perihelie, &excentriste, &demi_axe);

    trajectoire traj = new_trajectoire(365 * 50); // Révolution de la Terre * valeur assez grande
    planete nouv_planete = new_planete(planet.nom, masse, traj, perihelie); // planete rempli avec les valeurs
    trajectoire traj_p_euler = euler(nouv_planete);
    printf("Euler termine\n");
    char nom_planete[100];
    strcpy(nom_planete, planet.nom);
    strcat(nom_planete, ".json");
    FILE *fichier1 = fopen(nom_planete, "w"); // mode écriture
    printf("Fichier ouvert\n");
    if (fichier1 == NULL){
        printf("Erreur : Impossible de créer le fichier JSON\n");
        return;
    }
    printf("Simulation en cours...\n");
    fprintf(fichier1, "{\n");
    fprintf(fichier1, "\"earth-euler\" : [\n");
    printf("Debut écriture\n");
    for (int i = 0; i < 365 * 50; i++){ // On rentre les valeurs des points pour créer une trajectoire
        point p = traj_p_euler.ensemble[i];
        fprintf(fichier1, "[[%e,%e,%e],[%e,%e,%e],%d]", p.r.x, p.r.y, p.r.z, p.v.x, p.v.y, p.v.z, p.t);
        if (i < 365 * 50 - 1)
            fprintf(fichier1, ",\n");
    }
    fprintf(fichier1, "\n]\n}");
    fclose(fichier1); // ferme le fichier
    printf("Fichier JSON généré avec succès !\n");
    free(traj_p_euler.ensemble);

    // idem avec autre méthode
    trajectoire traj_p_euler_asym = euler_asymetrique(nouv_planete);
    printf("Euler termine\n");
    char nom_planete1[100];
    strcpy(nom_planete1, planet.nom);
    strcat(nom_planete1, "_asym.json");
    FILE *fichier2 = fopen(nom_planete1, "w");
    printf("Fichier ouvert\n");
    if (fichier2 == NULL){
        printf("Erreur : Impossible de créer le fichier JSON\n");
        return;
    }
    printf("Simulation en cours...\n");
    fprintf(fichier2, "{\n");
    fprintf(fichier2, "\"earth-euler\" : [\n");
    printf("Debut ecriture\n");
    for (int i = 0; i < 365 * 50; i++){
        point p = traj_p_euler_asym.ensemble[i];
        fprintf(fichier2, "[[%e,%e,%e],[%e,%e,%e],%d]", p.r.x, p.r.y, p.r.z, p.v.x, p.v.y, p.v.z, p.t);
        if (i < 365 * 50 - 1)
            fprintf(fichier2, ",\n");
    }
    fprintf(fichier2, "\n]\n}");
    fclose(fichier2);
    printf("Fichier JSON généré avec succès !\n");
    free(traj_p_euler_asym.ensemble);

    free(traj.ensemble);
    return;
}
