#ifndef RETANGULO_HPP
#define RETANGULO_HPP

#include "Ponto.hpp"

class Retangulo{

public:

	Retangulo(Ponto centro);
	~Retangulo();

	void expande();
	bool contem(Ponto ponto);
	double getX();
	double getxMax();
	double getY();
	double getyMax();

private:

	double x, y, xMax, yMax, raio;
	Ponto centro;

};

#endif

