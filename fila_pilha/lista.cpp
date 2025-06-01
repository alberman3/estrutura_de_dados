#include <iostream>

using namespace std;

struct Nodo {
    int info;
    Nodo *prox;
};

class Lista {
private:
    Nodo *inicio; // ponteiro para o início da lista
public:
    Lista() { inicio = nullptr; } // construtor para inicializar
    void inserir_ordenada(int n);
    void exibir(); // função extra para visualizar a lista
};

void Lista::inserir_ordenada(int n) {
    Nodo *novo = new Nodo(); // criar novo nó

    if (novo == nullptr) return; // falha na alocação

    novo->info = n;
    novo->prox = nullptr;

    // Caso 1: lista vazia ou o novo elemento deve ser inserido no início
    if (inicio == nullptr || n < inicio->info) {
        novo->prox = inicio;
        inicio = novo;
    } else {
        Nodo *atual = inicio;
        Nodo *ant = nullptr;

        // Percorrer até achar posição correta
        while (atual != nullptr && atual->info < n) {
            ant = atual;
            atual = atual->prox;
        }

        ant->prox = novo;
        novo->prox = atual;
    }
}

void Lista::exibir() {
    Nodo *aux = inicio;
    while (aux != nullptr) {
        cout << aux->info << " -> ";
        aux = aux->prox;
    }
    cout << "NULL\n";
}

int main() {
    Lista l;

    l.inserir_ordenada(10);
    l.inserir_ordenada(5);
    l.inserir_ordenada(8);
    l.inserir_ordenada(3);

    l.exibir(); // Deve mostrar: 3 -> 5 -> 8 -> 10 -> NULL

    return 0;
}


