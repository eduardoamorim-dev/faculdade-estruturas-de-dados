#include <iostream>
using namespace std;

// Estrutura de nó da lista encadeada
struct No {
    int valor;
    No* prox;
    // Construtor padrão
    No() {
        valor = 0;
        prox = NULL;
    }
    // Construtor com valor inicial
    No(int _valor) {
        valor = _valor;
        prox = NULL;
    }
};

// Estrutura da fila
struct Fila {
    No* inicio;
    No* fim;
    int n;
    // Construtor padrão
    Fila() {
        inicio = NULL;
        fim = NULL;
        n = 0;
    }
    // Método para enfileirar um valor
    void enfileirar(int valor) {
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
    // Método para desenfileirar um valor
    void desenfileirar() {
        if (n == 0) return;
        No* aux = inicio;
        inicio = inicio->prox;
        delete aux;
        n--;
        if (n == 0) fim = NULL;
    }
    // Método para pegar o valor na frente da fila
    int frente() {
        if (inicio == NULL) return 0;
        return inicio->valor;
    }
};

// Estrutura da pilha
struct Pilha {
    No* topo;
    int n;
    // Construtor padrão
    Pilha() {
        topo = NULL;
        n = 0;
    }
    // Método para inserir um valor na pilha
    void inserir(int valor) {
        No* novo = new No(valor);
        novo->prox = topo;
        topo = novo;
        n++;
    }
    // Método para remover um valor da pilha
    void remover() {
        if (n == 0) return;
        No* aux = topo;
        topo = topo->prox;
        delete aux;
        n--;
    }
    // Método para pegar o valor no topo da pilha
    int topoPilha() {
        if (topo == NULL) return 0;
        return topo->valor;
    }
    // Método para limpar a pilha
    void limpar() {
        while (topo != NULL) {
            remover();
        }
    }
};

// Função para inverter a ordem dos elementos da fila
void inverterFila(Fila& f, Pilha& p) {
    // Passo 1: Transferir todos os elementos da fila para a pilha
    while (f.n > 0) {
        p.inserir(f.frente());
        f.desenfileirar();
    }
    
    // Passo 2: Transferir todos os elementos da pilha de volta para a fila
    while (p.n > 0) {
        f.enfileirar(p.topoPilha());
        p.remover();
    }
}

int main() {
    Fila f;
    Pilha p;
    cout << "Digite a quantidade de numeros que serao inseridos na fila." << endl;
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++){
        int numeroInserido;
        cin >> numeroInserido;
        f.enfileirar(numeroInserido);
    }
    
    inverterFila(f, p);
    
    cout << "Fila invertida:" << endl;
    while (f.n > 0) {
        cout << f.frente() << " ";
        f.desenfileirar();
    }
    
    return 0;
}
