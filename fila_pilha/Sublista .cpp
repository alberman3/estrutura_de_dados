
#include <iostream>

using namespace std;





struct Nodo
{
    int info;
    Nodo *prox;
};

class lista 
{
private:
Nodo* principal = nullptr; 
Nodo* sublistaPares = nullptr; 
public:
   
};

lista ::inserir principal (int n)
{
    Nodo *novo=new Nodo;

    if(novo==nullptr)
        return;
    
    novo->info=n;
    novo->prox=nullptr;
    inicio=nullptr;
    Nodo*atual=inicio;

    if(inicio=nullptr){
        inicio =novo;
    }else{
        while(atual!=nullptr){
      atual=atual->prox;
        }
    }
    atual=novo;

    
}

lista ::inserir sublista (/* args */)
{
    Nodo *atual=inicio;
    Nodo ultimopar=nullptr;
    Nodo* novoNo = new Nodo();
    inicio2=nullptr;
    while (atual != nullptr){

        


        if (atual->info%2==0){
            inicio2=atual;
               novoNo=atual->info;
               novoNO->prox=nullptr
               if(inicio2==nullptr){
                 inicio2=novoNo;
                 ultimopar=novoNo;
               }else{
                ultimopar->prox=novoNo;
                ultimopar=novoNo;
            }
        }
        atual=atual->prox
        
    }
}

