
#include <iostream>

using namespace std;



/* 
Implemente um programa em C para criar um editor de texto de somente uma frase
, como uma lista circular duplamente encadeada. O programa deverá:

a. A frase sempre deve estar visível na tela;
b. A frase pode ser percorrida em ambos os sentidos;
c. Uma palavra pode ser: inserida, corrigida ou eliminada em qualquer lugar da lista.

Palavra atual: Estrutura
E: Editar palavra atual
D: Inserir (depois da palavra atual)
S: Eliminar palavra
<: Palavra anterior

: Palavra posterior
X: Sair
Digite sua opção:
*/
    struct Nodo2

    {
        string info;
        struct Nodo2 *ant,*prox;
    };

    class ListaDuplaCircular{
       private:
        Nodo2 *inicio,*fim;


        public:
      ListaDuplaCircular(){
        inicio=nullptr;
        fim=nullptr;
      };

      void inserir(string palavra);
      string retirar(string palavra);
      void listar();
      void  mostrar();
      void mostrarMenu();
      bool editar(string palavraAntiga, string palavraNova);
    };

    void ListaDuplaCircular::inserir(string palavra){
         Nodo2 *novo;
         novo=new Nodo2();

         if(novo==nullptr){
            cout<<"não tem memoria"<<endl;
            return;
         }
         novo->info=palavra;

         if(inicio==nullptr){

            novo->ant=novo;
            novo->prox=novo;
            inicio=novo;
            fim=novo;
         }
         else{

            novo->prox=inicio;
            novo->ant=fim;
            fim->prox=novo;
            inicio->ant=novo;
            fim=novo;
         }



    }

    string ListaDuplaCircular::retirar(string palavra) {
        if(inicio == nullptr) {
            return "Lista vazia!";
        }

        Nodo2 *atual = inicio;
        bool encontrou = false;


        do {
            if(atual->info == palavra) {
                encontrou = true;
                break;
            }
            atual = atual->prox;
        } while(atual != inicio);

        if(!encontrou) {
            return "Palavra não encontrada!";
        }

        // se so tiver um nó na lista
        if(atual == inicio && atual == fim) {
            inicio = fim = nullptr;
        }
        //para remover o primeiro nó
        else if(atual == inicio) {
            inicio = atual->prox;
            inicio->ant = fim;
            fim->prox = inicio;
        }
        // para remover o ultimo nó
        else if(atual == fim) {
            fim = atual->ant;
            fim->prox = inicio;
            inicio->ant = fim;
        }
        //  para remover o nó do meio
        else {
            atual->ant->prox = atual->prox;
            atual->prox->ant = atual->ant;
        }

        string palavraRemovida = atual->info;
        delete atual;
        return "Removido: " + palavraRemovida;
    }

    bool ListaDuplaCircular::editar(string palavraAntiga, string palavraNova) {
        if(inicio == nullptr) {
            cout << "Lista vazia!" << endl;
            return false;
        }

        Nodo2 *atual = inicio;
        bool encontrou = false;

        // Busca circular pela palavra
        do {
            if(atual->info == palavraAntiga) {
                atual->info = palavraNova;  // Substitui a palavra
                encontrou = true;
                break;
            }
            atual = atual->prox;
        } while(atual != inicio);

        if(!encontrou) {
            cout << "Palavra não encontrada para edição!" << endl;
        }
        return encontrou;
    }





    void ListaDuplaCircular::listar() {
        if(inicio == nullptr) {
        cout << "Lista vazia!" << endl;
        return;
        }

        Nodo2 *atual = inicio;
        cout<< "Lista:";
        do {
         cout<<atual->info<< " ";
         atual=atual->prox;
        } while(atual !=inicio);
        cout <<endl;


    }


    void ListaDuplaCircular::mostrar() {
    cout << "Frase: ";
    listar();
}



    void ListaDuplaCircular::mostrarMenu() {
        cout << "\n=== MENU ===" << endl;
        cout << "1. Inserir palavra" << endl;
        cout << "2. Remover palavra" << endl;
        cout << "3. Listar palavras" << endl;
        cout << "4. Editar palavra" << endl;  // Nova opção
        cout << "5. Sair" << endl;
        cout << "Escolha uma opção: ";
    }


        int main() {
    ListaDuplaCircular editor;
    int opcao;
    string palavra, nova;

    do {
        system("cls || clear");
        editor.mostrarMenu();
        cin >> opcao;
        cin.ignore();

        switch(opcao) {
            case 1:
                cout << "Palavra a inserir: ";
                getline(cin, palavra);
                editor.inserir(palavra);
                break;
            case 2:
                cout << "Palavra a remover: ";
                getline(cin, palavra);
                cout << editor.retirar(palavra) << endl;
                system("pause");
                break;
            case 3:
                editor.listar();
                 cout << "Pressione ENTER para continuar...";
                  cin.ignore();

                break;
            case 4:
                cout << "Palavra a editar: ";
                getline(cin, palavra);
                cout << "Nova palavra: ";
                getline(cin, nova);
                if(editor.editar(palavra, nova)) {
                    cout << "Edição realizada com sucesso!" << endl;
                }
                system("pause");
                break;
            case 5:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
                system("pause");
        }
    } while(opcao != 5);

    return 0;
}
