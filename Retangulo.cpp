#include "Retangulo.hpp"

Retangulo::Retangulo(Ponto centro) {

	this->centro = centro;
	this->x = centro.pegaX();
	this->y = centro.pegaY();
	this->xMax = centro.pegaX();
	this->yMax = centro.pegaY();
	this->raio = 0;
}

Retangulo::~Retangulo(){}

void Retangulo::expande() {

	this->x -= 1000;
	this->y -= 1000;
	this->xMax += 1000;
	this->yMax += 1000;
	this->raio += 1000;
}

double Retangulo::getX()	{ return this->x; }
double Retangulo::getxMax() { return this->xMax; }
double Retangulo::getY()	{ return this->y; }
double Retangulo::getyMax() { return this->yMax; }

bool Retangulo::contem(Ponto ponto) {

	if (this->centro.dist(ponto) <= this->raio) return true;

	return false;
}