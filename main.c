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

int main(){
    vectorTest(); // Test fonction

    char chaine[100];
    printf ("Entrez votre planète ? ");
    fgets (chaine, 100, stdin);
    chaine[strlen (chaine) - 1] = '\0'; // supprimer le \n
    printf("\n");

    //création de fichier
    trajectoire traj = new_trajectoire(365);
    double masse;
    double perihelie;
    creer_fichier(new_planete(chaine,masse,traj,perihelie));
    creer_fichier(new_planete(chaine,masse,traj,perihelie));

    return 0;
}