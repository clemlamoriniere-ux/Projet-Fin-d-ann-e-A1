#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "energie.h"
#include "euler.h"
#include "constante.h"

double energie(point p, double masse){ // la masse sera définit dans le euler
/*
Calcul de l'énergie
*/
    double v = norme(p.r); // valeur de ||v||
    double r = norme(p.v); // valeur de ||r||

    double Ec = 0.5 * masse * v * v; // formule de l'énergie cinétique
    double Ep = -GRAVITY * MASSE_SOLEIL * masse / r; // formule de l'énergie potentielle

    return Ec + Ep; // formule de l'énergie mécanique
}