#include <iostream>

/*1. Escreva um programa que contenha duas variaveis inteiras.
Leia essas variáveis do teclado.
Em seguida, compare seus endereços e exiba o conteudo do maior endereço.
*/
using namespace std;


int main (){
    int a, b;

    printf("Digite o um valor inteiro para a variavel a: ");
    cin >> a;
    printf("Digite o um valor inteiro para a variavel b: ");
    cin >> b;

    int *p1 = &a;
    int *p2 = &b;

    if(p1 > p2){
        printf("A variavel a = %d possui o maior endereco = %d\n", a, p1);
    }else {
        printf("A variavel b = %d possui o maior endereco = %d\n", b, p2);
    }

    /*printf("%d %d\n", p1, p2);
    printf("%d %d\n", *p1, *p2);*/

    return 0;
}

