#ifndef HEAP_HPP
#define HEAP_HPP

#include "Dist.hpp"

#include <algorithm> // para std::swap
#include <iostream>

class Heap {

public:
    Heap(int maxsize);
    ~Heap();

    void Inserir(Dist x);
    Dist Remover();

    //Retorna true caso o heap esteja vazio, false caso contrário.
    bool Vazio();

    int getTam();
    int gettamMax();

    void imprimir();

private:
    int GetAncestral(int posicao);
    int GetSucessorEsq(int posicao);
    int GetSucessorDir(int posicao);

    bool contem(Dist nova);

    int tamanho;
    int tamMax;
    Dist* data;

    /* Funções necessárias para implementar o Heapify recursivo
     * Você pode apagar elas caso decida implementar o Heapify iterativo
     */
    void HeapifyPorBaixo(int posicao);
    void HeapifyPorCima(int posicao);
};

#endif

