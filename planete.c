#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "planete.h"

planete new_planete(char* nom1, double masse1,trajectoire traj1,double perihelie1){
/*
créer une nouvelle planète
*/
    planete planet;
    planet.nom = nom1;
    planet.masse = masse1;
    planet.traj = traj1;
    planet.perihelie = perihelie1;
    return planet;
}

void determiner_planete(char *nom, double *masse, double *perihelie, double *excentriste, double *demi_axe){
    /*
    Définir les valeurs selon la planète
    */
    int decalage = 'a' - 'A'; // décalage entre miniscule et majuscule
    int longueur = strlen(nom);
    char *nom_p = malloc(sizeof(char) * (longueur + 1)); // allocation de mémoire
    for (int i = 0; i < longueur; i++){
        if (nom[i] < 'a') // si nom[i] est une majuscule
            nom_p[i] = nom[i] + decalage;
        else{
            nom_p[i] = nom[i];
        }
    }
    nom_p[longueur] = '\0';
    if (strcmp(nom_p, "terre") == 0){ //s'ils sont égaux alors on attribue les valeurs
        *masse = MASSE_TERRE; // passage par pointeur
        *perihelie = PERIHELIE_TERRE;
        *excentriste = EXCENTRISTE_TERRE;
        *demi_axe = DEMI_AXE_TERRE;
    }
    else if (strcmp(nom_p, "mars") == 0){
        *masse = MASSE_MARS;
        *perihelie = PERIHELIE_MARS;
        *excentriste = EXCENTRISTE_MARS;
        *demi_axe = DEMI_AXE_MARS;
    }
    else if (strcmp(nom_p, "jupiter") == 0){
        *masse = MASSE_JUPITER;
        *perihelie = PERIHELIE_JUPITER;
        *excentriste = EXCENTRISTE_JUPITER;
        *demi_axe = DEMI_AXE_JUPITER;
    }
    else if (strcmp(nom_p, "saturne") == 0){
        *masse = MASSE_SATURNE;
        *perihelie = PERIHELIE_SATURNE;
        *excentriste = EXCENTRISTE_SATURNE;
        *demi_axe = DEMI_AXE_SATURNE;
    }
    free(nom_p); // libérer l'espace
}