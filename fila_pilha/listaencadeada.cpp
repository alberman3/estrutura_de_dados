
#include <iostream>

using namespace std;


struct Nodo
{
    int info;
    Nodo *prox;
};

/* Escreva uma função, em C, que receba uma lista simplesmente encadeada, e 
retorne uma lista ordenada (crescente) sem alocar espaços para novos 
elementos da lista. */
void inserirListaEncadeada(int n) {
    Nodo *novo = new Nodo();
    if (novo == nullptr) {
        cout << "Memória não alocada";
        return;
    }
    novo->info = n;
    novo->prox = nullptr;

    if (inicio == nullptr) {
        // Se a lista está vazia, o novo nó é o primeiro.
        inicio = novo;
    } else {
        // Se não, percorre até o último nó e insere.
        Nodo *atual = inicio;
        while (atual->prox != nullptr) {
            atual = atual->prox;
        }
        atual->prox = novo; // Insere no final.
    }
}
// ex  | 3/ |   | 1/ |  | 7/ |  | 2/ |
void ordenarListaEncadeada() {
    if (inicio == nullptr || inicio->prox == nullptr) {
        return; // Lista vazia ou com apenas um elemento já está ordenada.
    }

    Nodo *ordenada = nullptr; // Lista ordenada (inicialmente vazia).
    Nodo *atual = inicio;     // Percorre a lista original.

    while (atual != nullptr) {
        Nodo *proximo = atual->prox; // Salva o próximo nó antes de modificar.

        // Caso 1: Insere no início da lista ordenada.
        if (ordenada == nullptr || atual->info < ordenada->info) {
            atual->prox = ordenada;
            ordenada = atual;
        } 
        // Caso 2: Procura a posição correta na lista ordenada.
        else {
            Nodo *aux = ordenada;
            while (aux->prox != nullptr && aux->prox->info < atual->info) {
                aux = aux->prox;
            }
            // Insere após 'aux'.
            atual->prox = aux->prox;
            aux->prox = atual;
        }

        atual = proximo; // Avança para o próximo nó na lista original.
    }

    inicio = ordenada; // Atualiza o início da lista para a versão ordenada.
}

void removerListaEncadeada(int n){
Nodo *anterior,*proximo;

if(inicio=nullptr){
    cout<<"não tem oque remover"
    return ;
}

aux=inicio;
anterior=inicio;
proximo=aux->prox;
    while(aux!=nullptr){

        if(aux->info==n){
        anterior->prox=proximo;
        }else{
           anterior=aux;
          aux=aux->prox;
        }
       proximo=aux->prox;
    }
}

void listar() {
    if (inicio == nullptr) {
        cout << "Lista vazia!" << endl;
        return;
    }

    Nodo* atual = inicio; // Começa do primeiro nó
    cout << "Lista: ";
    
    while (atual != nullptr) {
        cout << atual->info << " -> "; // Imprime o valor do nó atual
        atual = atual->prox; // Avança para o próximo nó
    }
    
    cout << "nullptr" << endl; // Indica o fim da lista
}

int main() {
    // Insere alguns valores na lista
    inserirListaEncadeada(3);
    inserirListaEncadeada(1);
    inserirListaEncadeada(7);
    inserirListaEncadeada(2);

    // Lista original (desordenada)
    cout << "Antes da ordenacao:" << endl;
    listar(); // Saída: Lista: 3 -> 1 -> 7 -> 2 -> nullptr

    // Ordena a lista
    ordenarListaEncadeada();

    // Lista ordenada
    cout << "\nDepois da ordenacao:" << endl;
    listar(); // Saída: Lista: 1 -> 2 -> 3 -> 7 -> nullptr

    return 0;
}