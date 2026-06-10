typedef  struct vector_ {
    double x;
    double y;
    double z = 0.0;
}vector;

vector addition(vector vector1, vector vector2);
vector soustraction(vector vector1, vector vector2);
vector multiplication(vector vector1, double scalaire);
double norme(vector vector1);