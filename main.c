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
    vectorTest();

    char chaine[100];
    printf ("Entrez votre planète ? ");
    fgets (chaine, 100, stdin);
    chaine[strlen (chaine) - 1] = '\0';

    trajectoire traj = new_trajectoire(365);
    creer_fichier(new_planete(chaine,MASSE_TERRE,traj,PERIHELIE_TERRE));
    creer_fichier(new_planete(chaine,MASSE_MARS,traj,PERIHELIE_MARS));
    return 0;
}