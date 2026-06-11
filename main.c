#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "constante.h"
#include "planete.h"
#include "point.h"
#include "trajectoire.h"
#include "vector.h"

trajectoire euler(planete planet){

/*
Résolution de l'équation différentiel par la méthode d'Euler pour obtenir une trajectoire à convertir en JSON
*/

    vector position = new_vector(PERIHELIE_TERRE, 0, 0); // vecteur position initial
    double distance = norme(position); // norme du vecteur position

    // valeur initiale de la vitesse en y
    double vitesse_perihelie_y = sqrt((GRAVITY * MASSE_SOLEIL * (1 + EXCENTRISTE_TERRE)) / (DEMI_AXE_TERRE * (1 - EXCENTRISTE_TERRE)));
    // vecteur vitesse initial
    vector vitesse = new_vector(0, vitesse_perihelie_y, 0);

    // vecteur accélération
    vector acceleration = multiplication(position,-(GRAVITY * MASSE_SOLEIL) / pow(distance, 3));
    
    int dt = 86400;// pas de temps = 1 jour

    trajectoire traj;
    traj.ensemble = malloc(sizeof(point) * 365); // 365: Révolution de la Terre
    for (int i = 0; i < 365; i++){
        vector pos_t_plus_un = addition(position,multiplication(vitesse, dt));
        vector v_t_plus_un = addition(vitesse,multiplication(acceleration, dt));
        position = pos_t_plus_un; // nouvelle position
        vitesse = v_t_plus_un; // nouvelle vitesse
        distance = norme(position); // nouvelle norme
        acceleration = multiplication(position,-(GRAVITY * MASSE_SOLEIL) / pow(distance, 3)); // nouvelle accélération
        traj.ensemble[i] = new_point(pos_t_plus_un, v_t_plus_un, i*dt); // ajout d'un point pour former la trajectoire
    }
    return traj;
}

int main(){
    vectorTest();

    trajectoire traj = new_trajectoire(365); // 365: Révolution de la Terre
    planete Earth = new_planete("Terre",MASSE_TERRE,traj,PERIHELIE_TERRE);
    trajectoire traj_Earth = euler(Earth);
    printTrajectoire(traj_Earth, 365);
}