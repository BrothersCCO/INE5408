/*
 * Lancamento.cpp
 *
 *  Created on: Apr 21, 2014
 *      Author: ranieri
 */

#include "Lancamento.h"

Lancamento::Lancamento(char* nome, double valor) {
	this->_nome = nome;
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
