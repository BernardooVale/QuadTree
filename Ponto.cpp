#include "Ponto.hpp"

Ponto::Ponto() {

	this->x = -1;
	this->y = -1;
	this->ativado = false;
	this->id = -1;
	this->num = -1;
	this->cep = -1;
	this->ident = "";
	this->tipo_end = "";
	this->bairro = "";
	this->regional = "";
}

Ponto::Ponto(double x, double y) {

	this->x = x;
	this->y = y;
	this->ativado = false;
	this->id = -1;
	this->num = -1;
	this->cep = -1;
	this->ident = "";
	this->tipo_end = "";
	this->bairro = "";
	this->regional = "";
}

Ponto::Ponto(double x, double y, long id, int num, int cep, std::string ident, std::string tipo_end, std::string bairro, std::string regional) {

	this->x = x;
	this->y = y;
	this->ativado = false;
	this->id = id;
	this->num = num;
	this->cep = cep;
	this->ident = ident;
	this->tipo_end = tipo_end;
	this->bairro = bairro;
	this->regional = regional;
}

Ponto::~Ponto(){}

bool Ponto::operator==(const Ponto& outra) const {
	return this->x == outra.x && this->y == outra.y;
}

double Ponto::pegaX() { return this->x; }
double Ponto::pegaY() { return this->y; }
void Ponto::ativa() { this->ativado = true; }
void Ponto::desativa() { this->ativado = false; }