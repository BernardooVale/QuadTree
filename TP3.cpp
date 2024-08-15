#include <iostream>
#include <random>
#include <fstream>
#include <sstream>
#include <string>
#include "QuadTree.hpp"
#include "arvbin.hpp"
#include "Heap.hpp"

int main() {

    // Sistema de povoamento automatico
    //
    //std::uniform_real_distribution<double> unif(0, 10);
    //std::default_random_engine re;

    // Estruturas de dados basicas
    //
    QuadTree qt = QuadTree(0, 0, 10000000, 10000000);
    Arvbin arv;
    int k = 0;
    

    // Apoio do teste do heap
    // 
    //int b = 0;
    //Ponto pontos[50];


    // Sistema de povoamento automatico da QuadTree, desnecessário com a leitura de arquivo
    //
    /*  for (int i = 0; i < 10; i++) {
        Ponto novo = Ponto(unif(re), unif(re)); */
        /*  double x, y;
        std::cout << "Digite x e y: ";
        std::cin >> x >> y;
        Ponto novo = Ponto(x, y);   */
        /*  if (qt.nRepetido(novo)) {
            std::cout << novo.pegaX() << " " << novo.pegaY() << std::endl;
            qt.adPonto(novo);
        }
        else {
            i -= 1;
            std::cout << "Repetido" << std::endl;
        }
    }   */


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


        // Apoio para teste do heap
        //
        //pontos[b] = ponto;
        //b++;

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

    // Teste do heap !!!!! atencao, ele retorna em ordem decrescente
    //
    //
    //Ponto posInicioComp(609602.870838, 7796576.568843);
    //Heap heapComp(16);
    //
    // Dist teste(posInicioComp, 7000000);
    //
    //for (int i = 0; i < 50; i++) {
    //   Dist dist(pontos[i], posInicioComp.dist(pontos[i]));
    //   heapComp.Inserir(dist);
    //   if (dist.getDist() < teste.getDist()) {
    //       teste = dist;
    //   }
    //}
    //
    //heapComp.imprimir();


    // Teste do sistema de ativação
    // 
    //qt.ativa(arv.busca("05010600584"));
    //qt.desativa(arv.busca("05010600584"));


    //teste da QuadTree
    // 
    //qt.imprimir();


    // Teste da arvore
    // 
    //arv.imprimir();


    // Teste do sistema final
    //
    //
    //Ponto posInicio(612244.212043, 7807198.318325);
    //Heap* heap = new Heap(10);
    //Retangulo ret(posInicio.pegaX(), posInicio.pegaY(), posInicio.pegaX(), posInicio.pegaY());

    //while (heap->getTam() < heap->gettamMax()){
    //
    //    qt.procura(heap, ret, posInicio);
    //    ret.expande();
    //}

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

            while (heap->getTam() < heap->gettamMax()){
                
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

    //std::cout << std::endl;
    //heap->imprimir();

    //teste.imprimir();

    //delete heap;
    //heap = nullptr;
    arv.~Arvbin();
    qt.~QuadTree();
}