#ifndef QUADTREE_HPP
#define QUADTREE_HPP

#include "Ponto.hpp"
#include "Retangulo.hpp"
#include "Heap.hpp"
#include "Dist.hpp"

#include <iostream>

class QuadTree {

public:

	QuadTree(double x, double y, double larg, double alt);
	~QuadTree();

	void adPonto(Ponto novo);
	void imprimir();
	bool nRepetido(Ponto novo);
	void procura(Heap* heap, Retangulo ret, Ponto posIni);
	void ativa(Ponto busca);
	void desativa(Ponto busca);

private:

	Ponto ponto;
	double x, y, larg, alt;
	bool Efolha, cheio;

	// referenciando as famosas coordenadas politicas
	QuadTree* esqSup; // superior esquerdo
	QuadTree* esqInf; // inferior esquerdo
	QuadTree* dirSup; // superior direito
	QuadTree* dirInf; //inferior direito

	void Fractal();
	void adPontoRec(Ponto novo);
	bool contem(Retangulo retangulo);
	Ponto* pesquisar(Ponto busca);
};

#endif
