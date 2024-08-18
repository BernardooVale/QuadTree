#include "Dist.hpp"

#include <iostream>

Dist::Dist() {
	this->ponto = Ponto();
	this->dist = -1;
}

Dist::Dist(Ponto ponto, double dist) {

	this->ponto = ponto;
	this->dist = dist;
}

Dist::~Dist(){}

double Dist::getDist() { return this->dist; }
Ponto Dist::getPonto() { return this->ponto; }

void Dist::imprimir() {

	this->ponto.imprimir();
	std::cout << "(" << this->dist << ")" << std::endl;
}