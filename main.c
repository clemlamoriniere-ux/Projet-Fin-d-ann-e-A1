#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "constante.h"
#include "planete.h"
#include "point.h"
#include "trajectoire.h"
#include "vector.h"
#include "euler.h"
#include "fichier.h"

int main(){
    vectorTest();

    trajectoire traj = new_trajectoire(365);
    creer_fichier(new_planete("terre",MASSE_TERRE,traj,PERIHELIE_TERRE));
    creer_fichier(new_planete("mars",MASSE_MARS,traj,PERIHELIE_MARS));
    return 0;
}