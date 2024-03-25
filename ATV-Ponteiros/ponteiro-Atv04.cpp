#include <iostream>
#include <cmath>

/*4. Implemente uma função que calcule a área da superfície e o volume de uma esfera de raio R.
A area da superfície e o volume são dados, respectivamente, por:

A = 4 * p * R^2
V = 4/3 * p * R^3
*/
using namespace std;

void Area_Volume (double r, double *a, double *v){
    double p = 3.14159;

    *a = 4 * p * pow(r,2);

    *v = (4.0/3.0) * p * pow(r,3);

}

int main (){
    double r;
    double a, v;

    cin >> r;

    Area_Volume(r, &a, &v);

    //printf("%d %d\n", &a, &v);
    printf("%lf %lf\n", a, v);

    return 0;
}


