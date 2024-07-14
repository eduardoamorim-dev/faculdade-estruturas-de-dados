// 2. Crie um método que remove o segundo elemento da lista. Se a lista tiver tamanho <= 1, seu método não deve fazer nada.

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
    
    void removerSegundo() {
        if (n <= 1) return; 

        No* segundo = inicio->prox;
        inicio->prox = segundo->prox; 

        if (segundo == fim) { 
            fim = inicio; 
        }

        delete segundo; 
        n--; 
    }
};


int main() {
    
    Lista l; 


    l.inserirInicio(10); 
    l.inserirInicio(5);  
    
    l.inserirFinal(7);   
    l.inserirFinal(3);   

    l.imprimir(); 

    cout << "Removendo o segundo elemento:" << endl;
    l.removerSegundo();
    l.imprimir();

    return 0; 
}
