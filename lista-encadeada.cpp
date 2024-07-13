#include <iostream>

using namespace std;

// Definição da estrutura do nó
struct No {
    int valor;   // Armazena um valor inteiro
    No* prox;    // Aponta para o próximo nó na lista

    // Construtor padrão, inicializa o ponteiro prox como NULL
    No() {
        prox = NULL;
    }

    // Construtor que inicializa o valor e define prox como NULL
    No(int _valor) {
        valor = _valor;
        prox = NULL;
    }
};

// Definição da estrutura da lista
struct Lista {
    No* inicio;   // Aponta para o primeiro nó da lista
    No* fim;      // Aponta para o último nó da lista
    int n;        // Armazena a quantidade de elementos na lista

    // Construtor que inicializa a lista como vazia
    Lista() {
        inicio = NULL;
        fim = NULL;
        n = 0;
    }

    // Função para inserir um nó no início da lista
    void inserirInicio(int valor) {
        No* novo = new No(valor); // Cria um novo nó com o valor
        if (inicio == NULL) {
            // Se a lista está vazia, início e fim são o novo nó
            inicio = novo;
            fim = novo;
        } else {
            // Aponta para o antigo início e atualiza o início para o novo nó
            novo->prox = inicio;
            inicio = novo;
        }
        n++; // Incrementa a contagem de nós
    }

    // Função para inserir um nó no final da lista
    void inserirFinal(int valor) {
        No* novo = new No(valor); // Cria um novo nó com o valor
        if (inicio == NULL) {
            // Se a lista está vazia, início e fim são o novo nó
            inicio = novo;
            fim = novo;
        } else {
            // O antigo fim aponta para o novo nó e atualiza o fim para o novo nó
            fim->prox = novo;
            fim = novo;
        }
        n++; // Incrementa a contagem de nós
    }

    // Função para remover o nó do início da lista
    void removerInicio() {
        if (n == 0) return; // Se a lista está vazia, não faz nada
        if (n == 1) {
            // Se há apenas um nó, remove ele e define início e fim como NULL
            delete inicio;
            inicio = NULL;
            fim = NULL;
            n--;
            return;
        }
        // Guarda o nó atual do início, atualiza o início para o próximo nó e remove o antigo início
        No* aux = inicio;
        inicio = inicio->prox;
        delete aux;
        n--; // Decrementa a contagem de nós
    }

    // Função para remover o nó do final da lista
    void removerFinal() {
        if (n == 0) return; // Se a lista está vazia, não faz nada
        if (n == 1) {
            // Se há apenas um nó, remove ele e define início e fim como NULL
            delete inicio;
            inicio = NULL;
            fim = NULL;
            n--;
            return;
        }
        // Encontra o penúltimo nó, remove o último nó e atualiza o fim para o penúltimo nó
        No* aux = inicio;
        while (aux->prox != fim) {
            aux = aux->prox;
        }
        delete fim;
        fim = aux;
        aux->prox = NULL;
        n--; // Decrementa a contagem de nós
    }

    // Função para imprimir todos os valores da lista
    void imprimir() {
        No* aux = inicio; // Começa no início da lista
        while (aux != NULL) {
            printf("%d\n", aux->valor); // Imprime o valor do nó atual
            aux = aux->prox;            // Vai para o próximo nó
        }
    }
};

// Função principal
int main() {
    
    Lista l; // Cria uma nova lista

    // Insere alguns valores na lista
    l.inserirInicio(10); // Insere o valor 10 no início
    l.inserirInicio(5);  // Insere o valor 5 no início
    
    l.inserirFinal(7);   // Insere o valor 7 no final
    l.inserirFinal(3);   // Insere o valor 3 no final

    l.imprimir(); // Imprime todos os valores da lista

    return 0; // Indica que o programa terminou com sucesso
}
