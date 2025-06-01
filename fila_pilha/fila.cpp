#include <iostream>
using namespace std;

struct Nodo {
    int info;
    Nodo *prox;
};

class Fila {
private:
    Nodo *inicio, *fim;

public:
    Fila();
    void inserir(int n);
    int retirar();
    void listar();
};

Fila::Fila() {
    inicio = nullptr;
    fim = nullptr;
}

void Fila::inserir(int n) {
    Nodo *novo = new Nodo();

    if (novo == nullptr) {
        cout << "Sem memória." << endl;
        return;
    }

    novo->info = n;
    novo->prox = nullptr;

    if (inicio == nullptr) {
        inicio = novo;
    } else {
        fim->prox = novo;
    }

    fim = novo;
}

int Fila::retirar() {
    if (inicio == nullptr) {
        cout << "Fila vazia." << endl;
        return -1;
    }

    Nodo *aux = inicio;
    int n = aux->info;
    inicio = inicio->prox;
    delete aux;

    if (inicio == nullptr) {
        fim = nullptr;
    }

    return n;
}

void Fila::listar() {
    Nodo *aux = inicio;

    while (aux != nullptr) {
        cout << aux->info << " ";
        aux = aux->prox;
    }

    cout << endl;
}

int main() {
    Fila f;
    f.inserir(10);
    f.inserir(20);
    f.listar();
    cout << "Retirado: " << f.retirar() << endl;
    f.listar();
    return 0;
}
