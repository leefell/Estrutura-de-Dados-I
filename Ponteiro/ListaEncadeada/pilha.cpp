#include <iostream>
#include "pilha.h"
using namespace std;

pilha::pilha() {

    this->aux = NULL;
    this->topo = NULL;

}

pilha::pilha(const pilha& orig) {
}

pilha::~pilha() {
}

void pilha::menu() {
    
    // Tudo implementado
    
    int opc;
    cout << "\n=========== MENU =========== " << endl;
    cout << "[1] - Inserir valor à pilha " << endl;
    cout << "[2] - Remover valor da pilha " << endl;
    cout << "[3] - Mostrar valores da pilha" << endl;
    cout << "[4] - Pesquisar valor da pilha " << endl;
    cout << "[0] - Sair" << endl;
    cout << "============================" << endl;
    cout << "Opcao: ";
    cin >> opc;

    switch (opc) {
        case 1:
            this->inserirValor();
            this->menu();
            break;
        case 2:
            this->removerValor();
            this->menu();
            break;
        case 3:
            this->mostrarValores();
            this->menu();
            break;
        case 4:
            this->pesquisarValor();
            this->menu();
            break;
        case 0:
            cout << "\nSaindo." << endl;
            break;
        default:
            cout << "\nOpcao Invalida." << endl;
            this->menu();
    }
}

bool pilha::vazio(no *structRecebido){
    if(structRecebido == NULL)
        return true;
    else
        return false;
}

void pilha::inserirValor() {

    int x;

    cout << "Digite o valor a ser empilhado: ";
    this->aux = (struct no*) malloc(sizeof (aux));
    cin >> x;

    this->aux->valor = x;
    this->aux->ant = this->topo;
    this->topo = this->aux;
}

void pilha::removerValor() {
    if (!vazio(this->topo)) {
        this->aux = this->topo;
        this->topo = this->topo->ant;
        free(this->aux);
        cout << "\nRemovido com sucesso!";
    }
}

void pilha::mostrarValores() {
    no *p;
    p = this->topo;
    while (!vazio(p->ant)) {
        cout << p->valor << endl;
        p = p->ant;
    }
    
    cout << p->valor << endl;

void pilha::pesquisarValor(){
    int chave;
    cout << "Digite um valor para verificar se esta empilhado: ";
    cin >> chave;

    for (this->aux = this->topo; this->aux != NULL; this->aux = this->aux->ant) {
        if (chave == this->aux->valor) {
            cout << "Valor esta empilhado." << endl;
        } else {
            cout << "Valor nao esta empilhado." << endl;
        }
    }
}
