#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "point.h"

point new_point(vector r1, vector v1, int t){
    point p;
    p.r = r1;
    p.v = v1;
    p.t = t;
    return p;
}

int main(){
}