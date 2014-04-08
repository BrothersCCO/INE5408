/*
 * ListaContabil.h
 *
 *  Created on: Apr 8, 2014
 *      Author: ranieri
 */

#ifndef LISTACONTABIL_H_
#define LISTACONTABIL_H_

#include "definitions.h"
#include "Lancamento.hpp"
#include "List.hpp"

#define ERROLISTACHEIA EMPTY_STRUCTURE_ERROR
#define ERROPOSICAOLAN NOT_FOUND_ERROR

class ListaContabil: public List<Lancamento> {
public:
	ListaContabil() :
		DataStructure<Lancamento>::DataStructure(MAXLISTA), List<Lancamento>::List(MAXLISTA) {
	}

	int adiciona(Lancamento value) {
		try {
			this->DataStructure<Lancamento>::push(value);
			return 0;
		} catch (int &e) {
			return e;
		}
	}

	void destroiLista() {
		this->DataStructure<Lancamento>::clear();
	}

	bool listaVazia() {
		return this->DataStructure<Lancamento>::isEmpty();
	}

	Lancamento mostra(int index) {
		return this->peek(index);
	}

	int retiraDaPosicao(int index) {
		try {
			this->pop(index);
			return 0;
		} catch (int &e) {
			return e;
		}
	}

	Lancamento verTrasacao(int index) {
		return this->mostra(index);
	}

	int verUltimo() {
		return this->DataStructure<Lancamento>::m_ptr;
	}
};

#endif /* LISTACONTABIL_H_ */
