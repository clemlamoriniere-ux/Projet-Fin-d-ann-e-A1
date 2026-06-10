#include <stdlib.h>
#include <stdio.h>
#include "main.h"

vector addition(vector vector1, vector vector2){
    vector new_vector;
    new_vector->x = vector1->x + vector2->x;
    new_vector->y = vector1->y + vector2->y;
    new_vector->z = vector1->z + vector2->z;
    return new_vector;
}


