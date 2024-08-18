#ifndef PONTO_HPP
#define PONTO_HPP

#include <string>

class Ponto {

public:

	Ponto();
	Ponto(double x, double y);
	Ponto(double x, double y, long id, int num, int cep, std::string ident, std::string tipo_end, std::string nome, std::string bairro, std::string regional);
	~Ponto();

	bool operator==(const Ponto& outro) const;

	void setX(double x);
	void setY(double y);
	void setID(long id);
	void setNUM(int num);
	void setCEP(int cep);
	void setIDENT(std::string ident);
	void setTIPOEND(std::string tipo_end);
	void setBAIRRO(std::string bairro);
	void setREGIONAL(std::string regional);

	double pegaX();
	double pegaY();
	std::string pegaIdent();
	std::string pegaTipoEnd();
	std::string pegaNome();
	int pegaNum();
	std::string pegaBairro();
	std::string pegaRegional();
	int pegaCEP();
	bool status();
	void ativa();
	void desativa();
	void imprimir();
	double dist(Ponto dest);

private:

	std::string ident, tipo_end, nome, bairro, regional;
	long id;
	int num, cep;
	double x, y;
	bool ativado;

	bool existe();

};

#endif
