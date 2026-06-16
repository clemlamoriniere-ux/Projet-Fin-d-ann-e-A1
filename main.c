#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "constante.h"
#include "planete.h"
#include "point.h"
#include "trajectoire.h"
#include "vector.h"
#include "euler.h"
#include "fichier.h"
#include "energie.h"

int main(){
    vectorTest(); // Test fonction

    char chaine[100];
    printf ("Entrez votre planète ? ");
    fgets (chaine, 100, stdin);
    chaine[strlen (chaine) - 1] = '\0'; // supprimer le \n
    printf("\n");

    //création de fichier
    trajectoire traj = new_trajectoire(365); // Révolution de la planète
    double masse;
    double perihelie;
    char* liste_planete[6] = {"mercure","venus","mars","terre","jupiter","saturne"}; // uranus et neptune trop loin
    if(chaine == "*") // toutes les planètes
        for(int i=0;i<6;i++){
            planete p = new_planete(liste_planete[i],masse,traj,perihelie);
            creer_fichier(p);
        }
    else{
        planete p = new_planete(chaine,masse,traj,perihelie);
        creer_fichier(p);
    }
    free(traj.ensemble); // libérer de l'espace
    return 0;
}