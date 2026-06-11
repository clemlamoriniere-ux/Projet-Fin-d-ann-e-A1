#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "main.h"

vector addition(vector vector1, vector vector2)
{
    vector new_vector;
    new_vector.x = vector1.x + vector2.x;
    new_vector.y = vector1.y + vector2.y;
    new_vector.z = vector1.z + vector2.z;
    return new_vector;
}

vector soustraction(vector vector1, vector vector2)
{
    vector new_vector;
    new_vector.x = vector1.x - vector2.x;
    new_vector.y = vector1.y - vector2.y;
    new_vector.z = vector1.z - vector2.z;
    return new_vector;
}

vector multiplication(vector vector1, double scalaire)
{
    vector new_vector;
    new_vector.x = scalaire * vector1.x;
    new_vector.y = scalaire * vector1.y;
    new_vector.z = scalaire * vector1.z;
    return new_vector;
}

double norme(vector vector1)
{
    return sqrt(pow(vector1.x, 2) + pow(vector1.y, 2) + pow(vector1.z, 2));
}

vector new_vector(double x, double y, double z)
{
    vector vector1;
    vector1.x = x;
    vector1.y = y;
    vector1.z = z;
    return vector1;
}

void print_vector(vector vector1)
{
    printf("(%.2lf %.2lf %.2lf)\n", vector1.x, vector1.y, vector1.z);
}

void vectorTest()
{
    vector vector1 = new_vector(3.0, 3.0, 0.0);
    vector vector2 = new_vector(2.0, 2.0, 0.0);
    vector vector_addition = addition(vector1, vector2);
    print_vector(vector_addition);
    vector vector_soustraction = soustraction(vector1, vector2);
    print_vector(vector_soustraction);
    vector vector_multiplication = multiplication(vector1, 2.0);
    print_vector(vector_multiplication);
    double norme_vector = norme(vector1);
    printf("norme : %.2lf \n", norme_vector);
}

int main()
{
    vectorTest();
}

trajectoire euler(point p)
{
    // position  depart:
    //  valeur en x

    // vecteur position

    // vitesse depart
    // valeur en Y
    double vitesse_perihelie = sqrt(9.81 * terre.masse_soleil * (1 + terre.excentricite)) / sqrt(terre.demi_axe(1 - terre.excentricite));
    // vitesse en vecteur

    // val acc
    double acceleration_perihelie = (9.81 * terre.masse_soleil) // /x^2;

        // vect acc

        // pas de temps
        int dt = 123;

    trajectoire traj;
    traj->ensemble = malloc(sizeof(vector) * 365);
    for (int i = 0; i < 365; i++)
    {
        double x_t_plus_un = point.r.x + point.v.x * dt;
        maj acc
            maj pos r
                traj->ensemble[i] = (x_t_plus_un, vx + 1, i);
    }
    return traj;
}