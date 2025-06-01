#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo* prox;
};

// Imprimir os elementos a partir do início do ciclo
void imprimirciclo(Nodo* inicioCiclo) {
    Nodo* atual = inicioCiclo;
    cout << "Ciclo detectado: [";

    do {
        cout << atual->valor;
        atual = atual->prox;
        if (atual != inicioCiclo)
            cout << ", ";
    } while (atual != inicioCiclo);

    cout << "]" << endl;
}

// Detectar ciclo e imprimir se houver
void ciclo(Nodo* inicio) {
    Nodo *aux, *atual, *cicloptr;
    cicloptr = nullptr;
    atual = inicio;

    if (inicio == nullptr) {
        cout << "Lista vazia." << endl;
        return;
    }

    while (atual != nullptr) {
        aux = inicio;

        while (aux != atual) {
            if (atual->prox == aux) {
                cicloptr = aux;
                break;
            }
            aux = aux->prox;
        }

        if (cicloptr != nullptr) {
            imprimirciclo(cicloptr);
            return;
        }

        atual = atual->prox;
    }

    cout << "Não tem ciclo." << endl;
}
