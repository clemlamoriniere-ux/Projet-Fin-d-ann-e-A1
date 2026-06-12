#ifndef EULER_H
#define EULER_H
#include "planete.h"

trajectoire euler(planete planet);
trajectoire euler_asymetrique(planete planet);
void determiner_planete(char* nom, double* masse, double* perihelie, double* excentriste, double* demi_axe);

#endif