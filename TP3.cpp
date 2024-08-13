// TP3.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <random>
#include "QuadTree.hpp"

int main(){

    std::uniform_real_distribution<double> unif(0, 10);
    std::default_random_engine re;

    QuadTree qt = QuadTree(0, 0, 10, 10);

    for (int i = 0; i < 1000; i++) {
        Ponto novo = Ponto(unif(re), unif(re));
        /*double x, y;
        std::cout << "Digite x e y: ";
        std::cin >> x >> y;
        Ponto novo = Ponto(x, y);*/
        if (qt.nRepetido(novo)) {
            std::cout << novo.pegaX() << " " << novo.pegaY() << std::endl;
            qt.adPonto(novo);
        }
        else {
            i -= 1;
            std::cout << "Repetido" << std::endl;
        }
    }

    std::cout << std::endl;
    qt.imprimir();

    qt.~QuadTree();
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
