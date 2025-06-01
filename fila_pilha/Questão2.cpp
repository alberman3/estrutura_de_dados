#include <iostream>

using namespace std;


/*
  receba como parâmetro o ponteiro para o início de uma lista duplamente encadeada e um valor inteiro N.
  A função deve eliminar da lista o nó que contém N, bem como seu nó anterior e o nó sucessor, se existirem.
 */


struct Nodo
{
    int info;

    Nodo *prox,*ant;
};

class listaDupla
{

private:
    Nodo *inicio,*fim ;
public:

    listaDupla() {
        inicio = nullptr;
        fim = nullptr;
    }
   void  inserirLista(int n);
   void  imprimir();
   void  retirarANTPROX(int n );


};

void listaDupla::inserirLista(int n)
{
   Nodo *atual;
   Nodo *novo=new Nodo();

   if(novo==nullptr){
    cout<<"memoria não alocada";
   }

   novo->info=n;


   novo->prox = nullptr;
   novo->ant = nullptr;

   atual=inicio;

   if (inicio == nullptr) {

    inicio=fim=novo;
   } else {

        fim->prox = novo;
        novo->ant = fim;
        fim = novo;
   }

}
void  listaDupla::retirarANTPROX(int n ){
    Nodo *atual=inicio;

    if(inicio==nullptr){
        cout<<"nao tem oque retirar";
        return;
    }


    //encontrar  o nó do atual
         while (atual != nullptr && atual->info != n) {
        atual = atual->prox;
    }

      // se não encontrou o nó
         if(atual==nullptr)
                return;


        //se so tiver um nó
        if (inicio == atual && fim == atual) {
        delete atual;
        inicio = fim = nullptr;
        return;
    }

        //se o atual ta no inicio e tem mais de um nó
        if (atual == inicio) {
        Nodo *proximo = atual->prox;

        if (proximo != nullptr) {
            // Remove o próximo
            if (proximo == fim) {
                fim = atual;
                atual->prox = nullptr;
            } else {
                atual->prox = proximo->prox;
                proximo->prox->ant = atual;
            }
            delete proximo;
        }
    }
        //se atual ta no fim
         else if (atual == fim) {
        Nodo *anterior = atual->ant;

        if (anterior != nullptr) {
            // Remove o anterior
            if (anterior == inicio) {
                inicio = atual;
                atual->ant = nullptr;
            } else {
                anterior->ant->prox = atual;
                atual->ant = anterior->ant;
            }
            delete anterior;
        }
    }
    // atual tá no meio

    else {
    // remove anterior
    if (atual->ant != nullptr) {
        Nodo *anterior = atual->ant;

        if (anterior == inicio) {
            inicio = atual;
            atual->ant = nullptr;
        } else {
            anterior->ant->prox = atual;
            atual->ant = anterior->ant;
        }
        delete anterior;
    }


    if (atual->prox != nullptr) {
        Nodo *proximo = atual->prox;

        if (proximo == fim) {
            fim = atual;
            atual->prox = nullptr;
        } else {
            proximo->prox->ant = atual;
            atual->prox = proximo->prox;
        }
        delete proximo;
    }
}

}



void listaDupla::imprimir() {
    Nodo* atual = inicio;
    while (atual != nullptr) {
        cout << atual->info << " ";
        atual = atual->prox;
    }
    cout << endl;
}


int main() {
    listaDupla lista;
    lista.inserirLista(10);
    lista.inserirLista(20);
    lista.inserirLista(40);
    lista.retirarANTPROX(20);
    lista.imprimir();

    return 0;
}