#include "QuadTree.hpp"

QuadTree::QuadTree(double x, double y, double larg, double alt) {

	this->x = x;
	this->y = y;
	this->larg = larg;
	this->alt = alt;
	this->esqSup = nullptr;
	this->esqInf = nullptr;
	this->dirSup = nullptr;
	this->dirInf = nullptr;
	this->Efolha = true;
	this->tam = 0;
}

QuadTree::~QuadTree() {

	delete this->esqSup;
	this->esqSup = nullptr;
	delete this->esqInf;
	this->esqInf = nullptr;
	delete this->dirSup;
	this->dirSup = nullptr;
	delete this->dirInf;
	this->dirInf = nullptr;
}

void QuadTree::adPonto(Ponto novo) {

	if (this->tam < 4) { // se tem espaço sobrando
		this->pontos[tam] = novo;
		tam++;
	}
	else {
		if (Efolha) { // da filhos para ele
			std::cout << "explodiu" << std::endl;
			this->Fractal();
		}
		this->adPontoRec(novo); // adiciona o novo ponto no respectivo filho
	}
}

void QuadTree::Fractal() {
	
	double meioX = ((this->larg + this->x) / 2), 
			meioY = ((this->alt + this->y) / 2);
	
	std::cout << meioX << " " << meioY << std::endl;
																		// exemplo, largura 50 e altura 50
	this->esqSup = new QuadTree(this->x, meioY, meioX, this->alt);		// esquerda superior de (0,25) até (25,50) (x,y) 
	this->esqInf = new QuadTree(this->x, this->y, meioX, meioY);		// esquerda inferior de (0,0) até (25,25) (x,y) 
	this->dirSup = new QuadTree(meioX, meioY, this->larg, this->alt);	// direita superior de (25,25) até (50,50) (x,y) 
	this->dirInf = new QuadTree(meioX, this->y, this->larg, meioY);		// direita inferior de (25,0) até (50,25) (x,y) 

	this->Efolha = false;

	// passa seu valores para seus filhos
	for(int i = 0; i < 4; i++)
		this->adPontoRec(this->pontos[i]);

}

void QuadTree::adPontoRec(Ponto novo) {

	double meioX = ((this->larg + this->x) / 2),
			meioY = ((this->alt + this->y) / 2);

	if (novo.pegaX() >= meioX) { // direita do quadrante
		if (novo.pegaY() >= meioY) { // direita superior
			std::cout << "Direita superior" << std::endl;
			this->dirSup->adPonto(novo);
		}
		else { //direita inferior
			std::cout << "Direita inferior" << std::endl;
			this->dirInf->adPonto(novo);
		}
	}
	else { // esquerda do quadrante
		if (novo.pegaY() >= meioY) { // esquerda superior
			std::cout << "Esquerda superior" << std::endl;
			this->esqSup->adPonto(novo);
		}
		else { // esquerda inferior
			std::cout << "Esquerda inferior" << std::endl;
			this->esqInf->adPonto(novo);
		}
	}
}

void QuadTree::imprimir() {

	if (this->Efolha) {
		for (int i = 0; i < 4; i++)
			std::cout << this->pontos[i].pegaX() << " " << this->pontos[i].pegaY() << std::endl;
	}
	else {

		std::cout << std::endl << "Superior esquerdo:" << std::endl << std::endl;
		this->esqSup->imprimir();
		std::cout << std::endl << "Inferior esquerdo:" << std::endl << std::endl;
		this->esqInf->imprimir();
		std::cout << std::endl << "Superior direito:" << std::endl << std::endl;
		this->dirSup->imprimir();
		std::cout << std::endl << "Inferior direito:" << std::endl << std::endl;
		this->dirInf->imprimir();
	}
}

Ponto* QuadTree::pesquisar(Ponto busca) {

	if (this->Efolha) {
		for (int i = 0; i < 4; i++) {
			if (this->pontos[i] == busca) {
				return &this->pontos[i];
			}
		}
		return nullptr;
	}
	else {
		double meioX = ((this->larg + this->x) / 2),
				meioY = ((this->alt + this->y) / 2);

		if (busca.pegaX() >= meioX) { // direita do quadrante
			if (busca.pegaY() >= meioY) { // direita superior
				return this->dirSup->pesquisar(busca);
			}
			else { //direita inferior
				return this->dirInf->pesquisar(busca);
			}
		}
		else { // esquerda do quadrante
			if (busca.pegaY() >= meioY) { // esquerda superior
				return this->esqSup->pesquisar(busca);
			}
			else { // esquerda inferior
				return this->esqInf->pesquisar(busca);
			}
		}
	}
}

bool QuadTree::nRepetido(Ponto novo) {

	Ponto* busca = this->pesquisar(novo);

	return (busca == nullptr ? true : false);
}