#ifndef PONTO_HPP
#define PONTO_HPP

#include <string>

class Ponto{

public:

	Ponto();
	Ponto(double x, double y);
	Ponto(double x, double y, long id, int num, int cep, std::string ident, std::string tipo_end, std::string bairro, std::string regional);
	~Ponto();

	bool operator==(const Ponto& outro) const;

	double pegaX();
	double pegaY();
	void ativa();
	void desativa();

private:

	std::string ident, tipo_end, nome_end, bairro, regional;
	long id;
	int num, cep;
	double x, y;
	bool ativado;

};

#endif

