#ifndef MAIN_H
#define MAIN_H

typedef  struct vector_ {
    double x;
    double y;
    double z;
}vector;

typedef  struct point_ {
    vector r;
    vector v;
    int t;
}p;

typedef  struct trajectoire_ {
    vector* ensemble;
}trajectoire;

typedef  struct planete_ {
    char* nom;
    double masse;
    trajectoire traj;
    double periphelie;
}planete;

vector addition(vector vector1, vector vector2);
vector soustraction(vector vector1, vector vector2);
vector multiplication(vector vector1, double scalaire);
double norme(vector vector1);

vector new_vector(double x, double y,double z);
void print_vector(vector vector1);

#endif // main.h