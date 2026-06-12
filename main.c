#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "constante.h"
#include "planete.h"
#include "point.h"
#include "trajectoire.h"
#include "vector.h"
#include "euler.h"

int main(){
    vectorTest();

    trajectoire traj = new_trajectoire(365 * 50); // 365: Révolution de la Terre
    planete Earth = new_planete("Terre", MASSE_TERRE, traj, PERIHELIE_TERRE);
    trajectoire traj_Earth = euler(Earth);
    printf("Euler termine\n");
    FILE *fichier = fopen("trajectoire.json", "w");
    printf("Fichier ouvert\n");
    if (fichier == NULL){
        printf("Erreur : Impossible de creer le fichier JSON\n");
        return 1;
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

    planete Earth_asymp = new_planete("Terre", MASSE_TERRE, traj, PERIHELIE_TERRE);
    trajectoire traj_Earth_asymp = euler_asymetrique(Earth);
    printf("Euler asymètrique terminé\n");
    FILE *fichier_asymp = fopen("trajectoire_asymp.json", "w");
    printf("Fichier ouvert\n");
    if (fichier_asymp == NULL){
        printf("Erreur : Impossible de creer le fichier JSON\n");
        return 1;
    }
    printf("Simulation en cours...\n");
    fprintf(fichier_asymp, "{\n");
    fprintf(fichier_asymp, "\"earth-euler\" : [\n");
    printf("Debut ecriture\n");
    for (int i = 0; i < 365 * 50; i++){
        point p = traj_Earth_asymp.ensemble[i];
        fprintf(fichier_asymp, "[[%e,%e,%e],[%e,%e,%e],%d]", p.r.x, p.r.y, p.r.z, p.v.x, p.v.y, p.v.z, p.t);
        if (i < 365 * 50 - 1)
            fprintf(fichier_asymp, ",\n");
    }
    fprintf(fichier_asymp, "\n]\n}");
    fclose(fichier_asymp);
    printf("Fichier 'trajectoire_asymp.json' genere avec succes !\n");
    free(traj_Earth_asymp.ensemble);
    free(traj.ensemble);

    return 0;
}