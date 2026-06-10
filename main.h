#ifndef MAIN_H
#define MAIN_H

typedef  struct vector_ {
    double x;
    double y;
    double z;
}vector;

vector addition(vector vector1, vector vector2);
vector soustraction(vector vector1, vector vector2);
vector multiplication(vector vector1, double scalaire);
double norme(vector vector1);

vector new_vector(double x, double y,double z);
void print_vector(vector vector1);

#endif // main.h