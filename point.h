#ifndef POINT_H
#define POINT_H

#include "vector.h"

typedef struct point_{
    vector r; // rx, ry, rz
    vector v;
    int t;
} point;

#endif