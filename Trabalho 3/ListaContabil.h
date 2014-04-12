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

#define ERROLISTACHEIA FULL_STRUCTURE_ERROR
#define ERROPOSICAOLAN NOT_FOUND_ERROR

class ListaContabil: public List<Lancamento> {
public:
	ListaContabil() :
		List<Lancamento>::List(MAXLISTA) {
	}

	int adiciona(Lancamento value) {
		try {
			this->push(value);
			return 0;
		} catch (int e) {
			return e;
		}
	}

	void destroiLista() {
		this->clear();
	}

	bool listaVazia() {
		return this->isEmpty();
	}

	Lancamento mostra(int index) {
		return this->peek(index);
	}

	int retiraDaPosicao(int index) {
		try {
			this->pop(index);
			return 0;
		} catch (int e) {
			return e;
		}
	}

	Lancamento verTrasacao(int index) {
		return this->mostra(index);
	}

	int verUltimo() {
		return this->m_ptr;
	}
};

#endif /* LISTACONTABIL_H_ */
