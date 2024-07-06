#include <iostream>

// Definição da estrutura do nó da lista
struct No {
    int dado;        // Dado armazenado no nó
    No* proximo;     // Ponteiro para o próximo nó na lista
};

// Função para inserir um elemento no início da lista
void inserirNoInicio(No*& cabeca, int novoDado) {
    No* novoNo = new No();      // Cria um novo nó
    novoNo->dado = novoDado;    // Atribui o dado ao novo nó
    novoNo->proximo = cabeca;   // O próximo do novo nó aponta para o antigo cabeça
    cabeca = novoNo;            // Atualiza o cabeça para apontar para o novo nó
}

// Função para imprimir os elementos da lista
void imprimirLista(No* cabeca) {
    No* atual = cabeca;         // Começa do cabeça
    std::cout << "Elementos da lista: ";
    while (atual != nullptr) {  // Enquanto não chegar ao fim da lista
        std::cout << atual->dado << " ";  // Imprime o dado do nó atual
        atual = atual->proximo;  // Move para o próximo nó
    }
    std::cout << std::endl;
}

// Função para remover o primeiro elemento da lista
void removerPrimeiro(No*& cabeca) {
    if (cabeca == nullptr) return;  // Se a lista estiver vazia, retorna

    No* temp = cabeca;              // Guarda o nó atual
    cabeca = cabeca->proximo;       // Move o cabeça para o próximo nó
    delete temp;                    // Deleta o nó original
}

// Função para liberar a memória alocada pela lista
void deletarLista(No*& cabeca) {
    No* atual = cabeca;
    while (atual != nullptr) {
        No* proximo = atual->proximo; // Guarda o próximo nó
        delete atual;                 // Deleta o nó atual
        atual = proximo;              // Move para o próximo nó
    }
    cabeca = nullptr;                 // Define o cabeça como nulo (lista vazia)
}

int main() {
    No* cabeca = nullptr;           // Lista vazia no início

    // Inserindo elementos na lista
    inserirNoInicio(cabeca, 10);
    inserirNoInicio(cabeca, 20);
    inserirNoInicio(cabeca, 5);

    // Imprimindo os elementos da lista
    imprimirLista(cabeca);

    // Removendo o primeiro elemento da lista
    removerPrimeiro(cabeca);

    // Imprimindo os elementos da lista após a remoção
    imprimirLista(cabeca);

    // Liberando a memória alocada pela lista
    deletarLista(cabeca);

    return 0;
}
