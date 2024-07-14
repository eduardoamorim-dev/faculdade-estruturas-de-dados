// 5. Crie um método que insere um elemento sempre na penúltima posição da lista. Se a lista tiver tamanho <= 1, seu método não deve fazer nada.

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


    void inserirInicio(int valor) {
        No* novo = new No(valor); 
        if (inicio == NULL) {

            inicio = novo;
            fim = novo;
        } else {

            novo->prox = inicio;
            inicio = novo;
        }
        n++; 
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

    void imprimir() {
        No* aux = inicio; 
        while (aux != NULL) {
            printf("%d\n", aux->valor); 
            aux = aux->prox;            
        }
    }
    
    
    void inserirPenultimaPosicao(int valor) {
        if (n <= 1) return; 
        
        No* novo = new No(valor);
        No* aux = inicio;
        
        
        while (aux->prox != fim) {
            aux = aux->prox;
        }
        
        novo->prox = aux->prox; 
        aux->prox = novo; 
        
        n++; 
    }
};


int main() {
    
    Lista l; 

    l.inserirInicio(10); 
    l.inserirInicio(5);  
    
    l.inserirFinal(7);   
    l.inserirFinal(3);   

    l.imprimir(); 

    cout << "Inserindo elemento na penúltima posição:" << endl;
    l.inserirPenultimaPosicao(15);
    l.imprimir();

    return 0; 
}
