#ifndef PLANETE_H
#define PLANETE_H

typedef struct planete_
{
    char *nom;
    double masse;
    trajectoire traj;
    double periphelie;
} planete;

typedef struct terre_
{
    double masse = 5.972 * pow(10, 24);
    double perihelie = 147099894000.0;
    double excentricite = 0.01671022;
    double demi_axe = 149597870700.0;
    double masse_soleil = 1.989 * pow(10, 30);
} terre;

#endif