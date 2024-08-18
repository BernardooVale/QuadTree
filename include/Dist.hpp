#ifndef DIST_HPP
#define DIST_HPP

#include "Ponto.hpp"

class Dist {

public:

	Dist();
	Dist(Ponto ponto, double dist);
	~Dist();

	double getDist();
	Ponto getPonto();
	void imprimir();

private:

	Ponto ponto;
	double dist;

};

#endif

