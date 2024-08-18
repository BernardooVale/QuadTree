#include "arvbin.hpp"

Arvbin::Arvbin() {

	this->esq = nullptr;
	this->dir = nullptr;
	this->ponto = Ponto();
}

Arvbin::Arvbin(Ponto novo) {
	this->esq = nullptr;
	this->dir = nullptr;
	this->ponto = novo;
}

Arvbin::~Arvbin() {

		delete this->esq;
		this->esq = nullptr;
		delete this->dir;
		this->dir = nullptr;
}

void Arvbin::adNo(Arvbin* novo) {

	if (this->ponto.pegaIdent() < novo->ponto.pegaIdent()) { // id do novo e maior

		if (this->dir == nullptr) {
			this->dir = novo;
		}
		else {
			this->dir->adNo(novo);
		}

	}
	else {

		if (this->esq == nullptr) {
			this->esq = novo;
		}
		else {
			this->esq->adNo(novo);
		}
	}
}

void Arvbin::imprimir() {

	if (this->esq != nullptr) {
		this->esq->imprimir();
	}

	this->ponto.imprimir();

	if (this->dir != nullptr) {
		this->dir->imprimir();
	}

}

Ponto Arvbin::busca(std::string busca) {

	if (this->ponto.pegaIdent() == busca) {
		return this->ponto;
	}
	else if (this->ponto.pegaIdent() < busca) {
		return this->dir->busca(busca);
	}
	else {
		return this->esq->busca(busca);
	}
}

Ponto Arvbin::getPonto() { return this->ponto; }
void Arvbin::setPonto(Ponto novo) { this->ponto = novo; }