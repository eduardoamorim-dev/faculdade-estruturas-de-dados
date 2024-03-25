#include <iostream>

/*2. Crie um programa que contenha um array de float contendo 10 elementos.
Imprima o endere�o de cada posi��o do array.
*/
using namespace std;


int main (){
    float v[10];

    for (int i = 0; i < 10 ; i++){
        cin >> v[i];
    }

    for (int i = 0; i < 10 ; i++){
        printf("Endereco da posicao %d : %d\n", i, &v[i]);

    }



    return 0;
}


