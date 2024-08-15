#include "Heap.hpp"
#include <algorithm> // para std::swap
#include <iostream>

// Construtor que inicializa o heap com um tamanho máximo e configura o tamanho atual como zero
Heap::Heap(int tam) : tamanho(0) {
    data = new Dist[tam];
    this->tamMax = tam;
}

// Destrutor que libera a memória alocada para o heap
Heap::~Heap() {

    delete[] this->data;
    this->data = nullptr;
}

// Função para verificar se o heap está vazio
bool Heap::Vazio() {
    return this->tamanho == 0 ? true : false;
}

// Função para inserir um novo elemento no heap
void Heap::Inserir(Dist x) {
    
    if(!this->contem(x) && x.getPonto().status()){
        if (this->Vazio()) {

            this->data[this->tamanho] = x;
            this->tamanho++;
        }
        else if (this->tamanho < tamMax) {

            this->data[this->tamanho] = x;
            HeapifyPorBaixo(this->tamanho);
            this->tamanho++;
        }
        else {
            if (x.getDist() < this->data[0].getDist()) {
                this->data[0] = x;
                this->HeapifyPorCima(0);
            }
        }
    }
}

// Função para remover e retornar o menor elemento do heap 
Dist Heap::Remover() {
    
    Dist retorno = this->data[0];
    this->data[0] = this->data[--tamanho];

    this->HeapifyPorCima(0);

    return retorno;
}

// Função para obter o índice do ancestral de um nó
int Heap::GetAncestral(int posicao) {
    return (posicao - 1) / 2;
}

// Função para obter o índice do sucessor esquerdo de um nó
int Heap::GetSucessorEsq(int posicao) {
    return (2 * posicao) + 1;
}

// Função para obter o índice do sucessor direito de um nó
int Heap::GetSucessorDir(int posicao) {
    return (2 * posicao) + 2;
}

// Função para manter a propriedade de min-heap "por baixo"
void Heap::HeapifyPorBaixo(int posicao) {

    int id_ancestral = this->GetAncestral(posicao);

    if (this->data[posicao].getDist() > this->data[id_ancestral].getDist()) {
        std::swap(this->data[posicao], this->data[id_ancestral]);
        if(id_ancestral != 0){
            this->HeapifyPorBaixo(id_ancestral);
        }
    }
}

// Função para manter a propriedade de min-heap "por cima"
void Heap::HeapifyPorCima(int posicao) {
    
    int id_e = this->GetSucessorEsq(posicao), id_d = this->GetSucessorDir(posicao);

    // se ambos existem
    if(id_e <= tamanho && id_d <= tamanho){

        //se o do meio e maior
        if (this->data[posicao].getDist() >= this->data[id_e].getDist() && this->data[posicao].getDist() >= this->data[id_d].getDist()) return;
        //se o da dir e maior
        if (this->data[id_d].getDist() > this->data[id_e].getDist()) {
            std::swap(this->data[posicao], this->data[id_d]);
            this->HeapifyPorCima(id_d);
            return;
        }
        //se o da esq e menor
        std::swap(this->data[posicao], this->data[id_e]);
        this->HeapifyPorCima(id_e);
        return;
    }

    // se so da esquerda existir
    if (id_e <= tamanho) {

        //se o do meio e maior
        if (this->data[posicao].getDist() >= this->data[id_e].getDist()) return;
        //se o da esq e maior
        std::swap(this->data[posicao], this->data[id_e]);
        this->HeapifyPorCima(id_e);
    }

    //se so da direita existir
    if (id_d <= tamanho) {

        //se o do meio e maior
        if (this->data[posicao].getDist() >= this->data[id_d].getDist()) return;
        //se o da dir e menor
        std::swap(this->data[posicao], this->data[id_d]);
        this->HeapifyPorCima(id_d);
    }

    //se nenhum existir
    return;
}

bool Heap::contem(Dist nova) {

    for (int i = 0; i < this->tamanho; i++)
        if (this->data[i].getPonto() == nova.getPonto()) return true;

    return false;
}

int Heap::getTam() { return this->tamanho; }
int Heap::gettamMax() { return this->tamMax; }

void Heap::imprimir() {

    Dist* dist = new Dist[this->tamanho];

    for (int i = this->tamMax; i > 0; i--)
        dist[i - 1] = this->Remover();

    for (int i = 0; i < this->tamMax; i++){

        dist[i].imprimir();
    }

    delete[] dist;
}
