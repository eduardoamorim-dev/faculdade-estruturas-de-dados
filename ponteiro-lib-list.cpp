#include <iostream>
#include <list>

int main() {
    // Criando uma lista encadeada de inteiros
    std::list<int> minhaLista;

    // Inserindo elementos na lista
    minhaLista.push_back(10); // Adiciona 10 no final da lista
    minhaLista.push_back(20); // Adiciona 20 no final da lista
    minhaLista.push_front(5); // Adiciona 5 no início da lista

    // Iterando pela lista usando um iterador
    std::cout << "Elementos da lista: ";
    for (auto it = minhaLista.begin(); it != minhaLista.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Removendo elementos da lista
    minhaLista.pop_front(); // Remove o primeiro elemento (5)
    minhaLista.pop_back();  // Remove o último elemento (20)

    // Verificando o tamanho da lista
    std::cout << "Tamanho da lista: " << minhaLista.size() << std::endl;

    // Verificando se a lista está vazia
    if (minhaLista.empty()) {
        std::cout << "A lista está vazia." << std::endl;
    } else {
        std::cout << "A lista não está vazia." << std::endl;
    }

    return 0;
}


