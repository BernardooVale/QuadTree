#include "Ponto.hpp"

#include <iostream>
#include <math.h>

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
	this->ativado = true;
	this->id = -1;
	this->num = -1;
	this->cep = -1;
	this->ident = "";
	this->tipo_end = "";
	this->bairro = "";
	this->regional = "";
}

Ponto::Ponto(double x, double y, long id, int num, int cep, std::string ident, std::string tipo_end, std::string nome, std::string bairro, std::string regional) {

	this->x = x;
	this->y = y;
	this->ativado = true;
	this->id = id;
	this->num = num;
	this->cep = cep;
	this->ident = ident;
	this->tipo_end = tipo_end;
	this->nome = nome;
	this->bairro = bairro;
	this->regional = regional;
}

Ponto::~Ponto() {}

void Ponto::setX(double x) { this->x = x; }
void Ponto::setY(double y) { this->y = y; }
void Ponto::setID(long id) { this->id = id; }
void Ponto::setNUM(int num) { this->num = num; }
void Ponto::setCEP(int cep) { this->cep = cep; }
void Ponto::setIDENT(std::string ident) { this->ident = ident; }
void Ponto::setTIPOEND(std::string tipo_end) { this->tipo_end = tipo_end; }
void Ponto::setBAIRRO(std::string bairro) { this->bairro = bairro; }
void Ponto::setREGIONAL(std::string regional) { this->regional = regional; }

std::string Ponto::pegaIdent() { return this->ident; }
std::string Ponto::pegaTipoEnd() { return this->tipo_end; }
std::string Ponto::pegaNome() { return this->nome; }
int Ponto::pegaNum() { return this->num; }
std::string Ponto::pegaBairro() { return this->bairro; }
std::string Ponto::pegaRegional() { return this->regional; }
int Ponto::pegaCEP() { return this->cep; }

bool Ponto::operator==(const Ponto& outra) const {
	return this->x == outra.x && this->y == outra.y;
}

double Ponto::pegaX() { return this->x; }
double Ponto::pegaY() { return this->y; }

void Ponto::ativa() {

	if (this->ativado == true) {
		std::cout << "Ponto de recarga " << this->ident << " ja estava ativo." << std::endl;
	}
	else {
		std::cout << "Ponto de recarga " << this->ident << " ativado." << std::endl;
		this->ativado = true;
	}
}
void Ponto::desativa() {

	if (this->ativado == false) {
		std::cout << "Ponto de recarga " << this->ident << " ja estava desativado." << std::endl;
	}
	else {
		std::cout << "Ponto de recarga " << this->ident << " desativado." << std::endl;
		this->ativado = false;
	}
}

bool Ponto::status() { return this->ativado; }

void Ponto::imprimir() {

	if(this->existe()){
		/*std::cout << std::fixed << this->ident << ";" << this->id << ";" << this->tipo_end << ";" << this->nome << ";" << this->num << ";" <<
			this->bairro << ";" << this->regional << ";" << this->cep << ";" << this->x << ";" << this->y << ";Status: " << (this->ativado ? "Ativado" : "Desativado");
		std::cout << std::endl;
		std::cout << std::endl;*/

		std::cout << std::fixed << this->tipo_end << " " << this->nome << ", " << this->num << ", " << this->bairro << ", " << this->regional << ", " << this->cep << " ";
	}
}

double Ponto::dist(Ponto dest) {

	double a = dest.pegaX() - this->pegaX();
	double b = dest.pegaY() - this->pegaY();
	double c = (a * a) + (b * b);
	return sqrt(c);
}

bool Ponto::existe() {
	return ((this->x >= 0 && this->y >= 0) ? true : false);
}