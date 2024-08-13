#ifndef QUADTREE_HPP
#define QUADTREE_HPP

#include "Ponto.hpp"

#include <iostream>

class QuadTree{

public:

	QuadTree(double x, double y, double larg, double alt);
	~QuadTree();

	void adPonto(Ponto novo);
	void nFolha();
	void imprimir();
	bool nRepetido(Ponto novo);


private:

	Ponto pontos[4];
	double x, y, larg, alt;
	int tam;
	bool Efolha;

	// referenciando as famosas coordenadas politicas
	QuadTree* esqSup; // superior esquerdo
	QuadTree* esqInf; // inferior esquerdo
	QuadTree* dirSup; // superior direito
	QuadTree* dirInf; //inferior direito

	void Fractal();
	void adPontoRec(Ponto novo);
	Ponto* pesquisar(Ponto busca);
};

#endif

