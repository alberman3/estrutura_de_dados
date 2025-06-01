#include <iostream>
#include <cstdlib>

using namespace std;
struct Nodo {

    int info;

    struct Nodo *esq,*dir;

};

class Arvore {
    public:
    Nodo *raiz;

    Arvore();
    Nodo* inserir (Nodo *raiz, int n );
    void em_ordem(Nodo *raiz);
};

 Arvore::Arvore(){
    raiz=nullptr;
}

 Nodo* Arvore::inserir(Nodo *raiz,int n  ){
    if(raiz == nullptr){

        raiz=new Nodo();
        if(raiz==nullptr)
         exit(1);

        raiz->info = n;
        raiz->esq = nullptr;
        raiz->dir = nullptr;
        return raiz;
    }

     if(n > raiz->info)
     raiz->dir = inserir(raiz->dir , n);

     else if (n < raiz->info)
         raiz->esq = inserir(raiz->esq , n);

         else{
         cout<< "numero repetido"<<endl;


         }

         return raiz;


}

  void Arvore::em_ordem(Nodo *raiz){

      if(raiz == nullptr) return;

      em_ordem(raiz->esq);

      cout<<raiz->info;

      em_ordem(raiz->dir);


  }
int main()
{
    Arvore tree;

    tree.raiz=tree.inserir(tree.raiz,10);
    tree.raiz=tree.inserir(tree.raiz,20);
    tree.raiz=tree.inserir(tree.raiz,40);
    tree.raiz=tree.inserir(tree.raiz,5);


    cout << "Em ordem: ";
    tree.em_ordem(tree.raiz);



    return 0;
}
