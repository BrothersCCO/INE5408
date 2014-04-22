#include "Lancamento.h"
#include <cstring>

Lancamento::Lancamento(char* nome, double valor) {
	this->_nome = new char[strlen(nome) + 1];
    strcpy(this->_nome, nome);
	this->_valor = valor;
}

Lancamento::~Lancamento() {
	// TODO Auto-generated destructor stub
}

char* Lancamento::nome() {
	return this->_nome;
}

double Lancamento::valor() {
	return this->_valor;
}
