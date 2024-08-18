#ifndef ARVBIN_HPP
#define ARVBIN_HPP

#include "Ponto.hpp"

class Arvbin{

public:

	Arvbin();
	Arvbin(Ponto ponto);
	~Arvbin();

	void adNo(Arvbin* novo);
	void imprimir();
	Ponto getPonto();
	void setPonto(Ponto novo);
	Ponto busca(std::string busca);

private:

	Arvbin* esq;
	Arvbin* dir;
	Ponto ponto;

};

#endif 


