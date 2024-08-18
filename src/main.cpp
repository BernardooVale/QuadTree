#include <iostream>
#include <random>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include "QuadTree.hpp"
#include "arvbin.hpp"
#include "Heap.hpp"

int main() {



    // Estruturas de dados basicas
    //
    QuadTree qt = QuadTree(0, 0, 10000000, 10000000);
    Arvbin arv;
    int k = 0;


    // Sistema de leitura de um arvio .csv
    //
    std::ifstream arquivo("dados.csv");
    if (!arquivo.is_open()) {
        std::cerr << "Não foi possível abrir o arquivo." << std::endl;
    }

    std::string linha;

    while (std::getline(arquivo, linha)) {
        std::stringstream ss(linha);
        std::string ident, tipo_end, nome, bairro, regional, xS ,yS;
        long id;
        int num, cep;
        double x, y;

        // Lê e extrai os dados da linha
        std::getline(ss, ident, ';');
        ss >> id;
        ss.ignore(); // Ignora o delimitador ';'
        std::getline(ss, tipo_end, ';');
        std::getline(ss, nome, ';');
        ss >> num;
        ss.ignore(); // Ignora o delimitador ';'
        std::getline(ss, bairro, ';');
        std::getline(ss, regional, ';');
        ss >> cep;
        ss.ignore(); // Ignora o delimitador ';'
        ss >> x;
        ss.ignore(); // Ignora o delimitador ';'
        ss >> y;

        Ponto ponto(x, y, id, num, cep, ident, tipo_end, nome, bairro, regional);

        if (k == 0) {
            arv.setPonto(ponto);
            k++;
        }
        else {
            Arvbin* aux = new Arvbin(ponto);
            arv.adNo(aux);
        }
        qt.adPonto(ponto);
    }

    std::ifstream acoes("acoes.ev");

    if (!acoes.is_open()) {
        std::cerr << "Não foi possível abrir o arquivo." << std::endl;
    }

    while (std::getline(acoes, linha)) {

        std::stringstream ss(linha);
        std::string comando;

        std::getline(ss, comando, ' ');

        if (comando == "C") {
            double x, y;
            int numEst;

            // Ler o primeiro double
            ss >> x;
            ss.ignore();
            // Ler o segundo double
            ss >> y;
            ss.ignore();
            // Ler o int
            ss >> numEst;
            ss.ignore();

            Ponto posIni(x, y);
            Heap* heap = new Heap(numEst);
            Retangulo ret(posIni);

            while (heap->getTam() < heap->gettamMax()) {
                
                qt.procura(heap, ret, posIni);
                ret.expande();
            }

            std::cout << std::fixed << comando << " " << x << " " << y << " " << numEst << std::endl;
            heap->imprimir();

            delete heap;
            heap = nullptr;
        }
        else if (comando == "A") {

            std::string ident;
            std::getline(ss, ident, ' ');

            std::cout << comando << " " << ident << std::endl;
            qt.ativa(arv.busca(ident));
        } 
        else if (comando == "D") {

            std::string ident;
            std::getline(ss, ident, ' ');

            std::cout << comando << " " << ident << std::endl;
            qt.desativa(arv.busca(ident));
        }
    }
    arv.~Arvbin();
    qt.~QuadTree();
}