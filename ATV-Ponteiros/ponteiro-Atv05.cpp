#include <iostream>

/*5. Crie uma função que receba por parâmetro um vetor de números inteiros,
o tamanho do vetor e os endereços de duas variáveis inteiras (que podemos chamar de min e max).
Ao passar essas variáveis para a função seu programa deverá analisar qual é o maior e o menor elemento do vetor e depositar esses elementos nas variáveis do parâmetro.*/

using namespace std;

void Maior_Menor_elemento(int *v, int *n, int *min, int *max){
    for (int i = 0; i < *n ; i++){
       if(v[i] > *max) {
            *max = v[i];
       }else if(v[i] < *min){
            *min = v[i];
       }
    }
}


int main (){
    int n;

    printf("Qual e o tamanho do vetor: ");
    cin >> n;

    int v[n];

    for (int i = 0; i < n ; i++){
        cin >> v[i];
    }

    int min = v[0], max = v[0];

    Maior_Menor_elemento(v, &n, &min, &max);

    printf("Maior elemento: %d\nMenor elemento: %d\n", max, min);


    return 0;
}


