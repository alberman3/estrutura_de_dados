#include <iostream>
using namespace std;

struct Nodo {
    int info;
    Nodo *prox;
};

class PilhaD {
private:
    Nodo *topo;

public:
    PilhaD();
    void empilhar(int n);
    int desempilhar();
    void listar();
};

PilhaD::PilhaD() {
    topo = nullptr;
}

void PilhaD::empilhar(int n) {
    Nodo *novo = new Nodo;
    novo->info = n;

    if (topo == nullptr) {
        novo->prox = nullptr;
    } else {
        cout << "pilha" << endl;
        novo->prox = topo;
    }
    topo = novo;
}

int PilhaD::desempilhar() {
    if (topo == nullptr) {
        cout << "nao tem o que desempilhar" << endl;
        return -1;
    } else {
        Nodo *aux = topo;
        topo = aux->prox;
        int n = aux->info;
        delete aux;
        return n;
    }
}

void PilhaD::listar() {
    Nodo *aux = topo;

    while (topo != nullptr) {
        cout << aux->info << endl;
        aux = aux->prox;
    }
}

int main() {
    PilhaD p;
    p.empilhar(20);
    p.empilhar(30);
     p.empilhar(30);
      p.empilhar(30);
   // p.desempilhar();
    p.listar();
    return 0;
}
