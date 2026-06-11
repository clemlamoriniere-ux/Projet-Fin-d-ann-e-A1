#ifndef MAIN_H
#define MAIN_H

typedef struct vector_
{
    double x;
    double y;
    double z;
} vector;

typedef struct point_
{
    vector r; // rx, ry, rz
    vector v;
    int t;
} point;

typedef struct trajectoire_
{
    point *ensemble;
} trajectoire;

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

vector addition(vector vector1, vector vector2);
vector soustraction(vector vector1, vector vector2);
vector multiplication(vector vector1, double scalaire);
double norme(vector vector1);

vector new_vector(double x, double y, double z);
void print_vector(vector vector1);

#endif // main.h