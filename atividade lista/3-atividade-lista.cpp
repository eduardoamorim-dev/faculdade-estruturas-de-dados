// 3. Crie um método que seja capaz de inserir no final da lista o tamanho atual da lista.

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


    void removerInicio() {
        if (n == 0) return; 
        if (n == 1) {

            delete inicio;
            inicio = NULL;
            fim = NULL;
            n--;
            return;
        }

        No* aux = inicio;
        inicio = inicio->prox;
        delete aux;
        n--; 
    }

    void imprimir() {
        No* aux = inicio; 
        while (aux != NULL) {
            printf("%d\n", aux->valor); 
            aux = aux->prox;            
        }
    }
    
    void removerNUltimos(int N) {
        if (N >= n) {
            while (n > 0) {
                removerInicio();
            }
            return;
        }
        
        int m = n - N;
        No* aux = inicio;
        for (int i = 1; i < m; i++) {
            aux = aux->prox;
        }
        
        No* temp = aux->prox;
        aux->prox = NULL;
        fim = aux;
        
        while (temp != NULL) {
            No* prox = temp->prox;
            delete temp;
            temp = prox;
            n--;
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

    void inserirTamanhoAtual() {
        inserirFinal(n);
    }
};


int main() {
    
    Lista l; 


    l.inserirInicio(10); 
    l.inserirInicio(5);  
    
    l.inserirFinal(7);   
    l.inserirFinal(3);   

    
    l.removerSegundo();
    
    cout << "Inserindo o tamanho atual da lista no final:" << endl;
    l.inserirTamanhoAtual();
    l.imprimir();

    return 0; 
}
