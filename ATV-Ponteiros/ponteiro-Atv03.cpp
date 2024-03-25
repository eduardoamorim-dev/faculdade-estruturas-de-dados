#include <iostream>

/*3. Escreva uma função que dado um número real passado como parâmetro,
retorne a parte inteira e a parte fracionária deste número.
Escreva um programa que chama esta função.
*/
using namespace std;

void parte_int_frac (double *n, int *p_int, double *p_frac){
    *p_int = (int)*n;
    *p_frac = *n - *p_int;

}

int main (){
    double n;
    int p_int ;
    double p_frac;

    cin >> n;

    parte_int_frac(&n, &p_int , &p_frac);

    printf("Parte inteira = %d\nParte fracionada = %lf\n", p_int, p_frac);

    return 0;
}

