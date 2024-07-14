// 4. Crie um método que receba um número N e insira na lista todos os números de 1 até N.

#include <iostream>

using namespace std;

struct No {
    int valor;   
    No* prox;   


    No() {
        prox = NULL;
    }


    No(int _valor) {
        valor = _valor;
        prox = NULL;
    }
};


struct Lista {
    No* inicio;   
    No* fim;    
    int n;       


    Lista() {
        inicio = NULL;
        fim = NULL;
        n = 0;
    }

    void inserirFinal(int valor) {
        No* novo = new No(valor); 
        if (inicio == NULL) {

            inicio = novo;
            fim = novo;
        } else {

            fim->prox = novo;
            fim = novo;
        }
        n++; 
    }


    void inserirNumerosAteN(int N) {
        for (int i = 1; i <= N; ++i) {
            inserirFinal(i);
        }
    }
    
    void imprimir() {
        No* aux = inicio; 
        while (aux != NULL) {
            printf("%d\n", aux->valor); 
            aux = aux->prox;            
        }
    }
};


int main() {
    
    Lista l; 

    int N = 5; 

    l.inserirNumerosAteN(N);

    cout << "Inserindo números de 1 até " << N << " na lista:" << endl;
    l.imprimir();

    return 0; 
}
