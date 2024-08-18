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
	this->cheio = false;
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

	if (!this->cheio) { // se tem espaco sobrando
		ponto = novo;
		this->cheio = true;
	}
	else {
		if (this->Efolha) { // da filhos para ele
			this->Fractal();
		}
		this->adPontoRec(novo); // adiciona o novo ponto no respectivo filho
	}
}

void QuadTree::Fractal() {

	this->esqSup = new QuadTree(this->x, this->ponto.pegaY(), this->ponto.pegaX(), this->alt);		// esquerda superior de (0,25) at� (25,50) (x,y) 
	this->esqInf = new QuadTree(this->x, this->y, this->ponto.pegaX(), this->ponto.pegaY());		// esquerda inferior de (0,0) at� (25,25) (x,y) 
	this->dirSup = new QuadTree(this->ponto.pegaX(), this->ponto.pegaY(), this->larg, this->alt);	// direita superior de (25,25) at� (50,50) (x,y) 
	this->dirInf = new QuadTree(this->ponto.pegaX(), this->y, this->larg, this->ponto.pegaY());		// direita inferior de (25,0) at� (50,25) (x,y) 

	this->Efolha = false;
}

void QuadTree::adPontoRec(Ponto novo) {

	if (novo.pegaX() >= this->ponto.pegaX()) { // direita do quadrante
		if (novo.pegaY() >= this->ponto.pegaY()) {// direita superior
			this->dirSup->adPonto(novo);
		}
		else {// direita inferior
			this->dirInf->adPonto(novo);
		}
	}
	else {// esquerda do quadrante
		if (novo.pegaY() >= this->ponto.pegaY()) {// esquerda superior
			this->esqSup->adPonto(novo);
		}
		else {// esquerda inferior
			this->esqInf->adPonto(novo);
		}
	}
}

void QuadTree::imprimir() {

	this->ponto.imprimir();

	if(!this->Efolha){
		this->esqSup->imprimir();
		this->esqInf->imprimir();
		this->dirSup->imprimir();
		this->dirInf->imprimir();
	}
}

Ponto* QuadTree::pesquisar(Ponto busca) {

	if (this->ponto == busca) {
		return &this->ponto;
	}
	else {
		if(!this->Efolha){
			if (busca.pegaX() >= this->ponto.pegaX()) { // direita do quadrante
				if (busca.pegaY() >= this->ponto.pegaY()) {// direita superior
					if (this->dirSup != nullptr) return this->dirSup->pesquisar(busca);
				}
				else {// direita inferior
					if(this->dirInf != nullptr) return this->dirInf->pesquisar(busca);
				}
			}
			else {// esquerda do quadrante
				if (busca.pegaY() >= this->ponto.pegaY()) {// esquerda superior
					if (this->esqSup != nullptr) return this->esqSup->pesquisar(busca);
				}
				else {// esquerda inferior
					if (this->esqInf != nullptr) return this->esqInf->pesquisar(busca);
				}
			}
		}
	}
	return nullptr;
}

bool QuadTree::nRepetido(Ponto novo) {

	Ponto* busca = this->pesquisar(novo);
	return (busca == nullptr ? true : false);
}


// Verifica se as fronteiras do retangulo estao dentro dos limites da quadtree
bool QuadTree::contem(Retangulo retangulo) {

	if (this->x <= retangulo.getX() &&
		this->larg >= retangulo.getX() &&
		this->y <= retangulo.getY() &&
		this->alt >= retangulo.getY()) return true;

	if (this->x <= retangulo.getX() &&
		this->larg >= retangulo.getX() &&
		this->y <= retangulo.getyMax() &&
		this->alt >= retangulo.getyMax()) return true;

	if (this->x <= retangulo.getxMax() &&
		this->larg >= retangulo.getxMax() &&
		this->y <= retangulo.getY() &&
		this->alt >= retangulo.getY()) return true;

	if (this->x <= retangulo.getxMax() &&
		this->larg >= retangulo.getxMax() &&
		this->y <= retangulo.getyMax() &&
		this->alt >= retangulo.getyMax()) return true;

	if (retangulo.getX() <= this->x &&
		retangulo.getxMax() >= this->x &&
		retangulo.getY() <= this->y &&
		retangulo.getyMax() >= this->y) return true;

	if (retangulo.getX() <= this->x &&
		retangulo.getxMax() >= this->x &&
		retangulo.getY() <= this->alt &&
		retangulo.getyMax() >= this->alt) return true;

	if (retangulo.getX() <= this->larg &&
		retangulo.getxMax() >= this->larg &&
		retangulo.getY() <= this->y &&
		retangulo.getyMax() >= this->y) return true;

	if (retangulo.getX() <= this->larg &&
		retangulo.getxMax() >= this->larg &&
		retangulo.getY() <= this->alt &&
		retangulo.getyMax() >= this->alt) return true;

	if (this->x >= retangulo.getX() &&
		this->larg <= retangulo.getxMax() &&
		this->y >= retangulo.getY() &&
		this->alt <= retangulo.getyMax()) return true;

	if (this->x >= retangulo.getX() &&
		this->larg <= retangulo.getxMax() &&
		this->y <= retangulo.getY() &&
		this->alt >= retangulo.getyMax()) return true;

	if (this->x <= retangulo.getX() &&
		this->larg >= retangulo.getxMax() &&
		this->y >= retangulo.getY() &&
		this->alt <= retangulo.getyMax()) return true;

	return false;
}

void QuadTree::ativa(Ponto busca) { this->pesquisar(busca)->ativa(); }
void QuadTree::desativa(Ponto busca) { this->pesquisar(busca)->desativa(); }

void QuadTree::procura(Heap* heap, Retangulo ret, Ponto posIni) {

	if (ret.contem(this->ponto)) {
		Dist aux(this->ponto, posIni.dist(this->ponto));
		heap->Inserir(aux);
	}


	if (this->esqSup != nullptr && this->esqSup->contem(ret)) {
		this->esqSup->procura(heap, ret, posIni);
	} 

	if (this->esqInf != nullptr && this->esqInf->contem(ret)) {
		this->esqInf->procura(heap, ret, posIni);
	} 

	if (this->dirSup != nullptr && this->dirSup->contem(ret)) {
		this->dirSup->procura(heap, ret, posIni);
	} 

	if (this->dirInf != nullptr && this->dirInf->contem(ret)) {
		this->dirInf->procura(heap, ret, posIni);
	}

	/*
		aqui e a funcao que percorre a quadtree.
		a ideia e que cemece um retangulo com tamanho exato do ponto passado
		tambem sera passado um heap para armazenar todas as distancias
		enquanto o heap nao tiver cheio essa funcao sera chamada na main
		
		a ideia e que o retangulo seja repassado recursivamente entre as quadtrees, para aquelas que estao dentro da margem dele, usando a funcao .contem(Retangulo retangulo)
		caso o retangulo contem o ponto armazenado na quadtree, com a funcao retangulo.contem(this.ponto), esse ponto e armazenado dentro do heap,caso seja possivel
		
		a ideia e que o retangulo va aumentando enquanto nao forem encontrados postos suficientes e que, toda vez que ele aumente, todos os pontos dentro do seu raio tenham sido, ao menos, tentados a ser adicionados

		exemplo:

		o retangulo cresceu 3 vezes e achou o primeiro posto, adiciona 1 posto de 10, 1/10
		o retangulo cresceu 5 vezes e achou mais dois, 3/10
		o retangulo cresceu 10 vezes e achou mais 5, 8/10
		o retangulo cresceu mais uma vez e achou mais 3, nesse caso, a funcao nao sera mais chamada ja que o heap alcancou o numero proposto e a extração extra (11/10) , vulgo a mais longe das 11, será descartada.
	*/
}