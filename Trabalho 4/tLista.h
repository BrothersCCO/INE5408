/*
 * tLista.h
 *
 *  Created on: 10/04/2014
 *      Author: ranieri
 */

#ifndef TLISTA_H_
#define TLISTA_H_

#include <cstring>
#include "List.hpp"

typedef char* T;
class tLista: public List<T> {
public:
	tLista() :
			List<T>::List(MAXLISTA), ultimo(this->m_ptr) {
	}

	void adicionar(const T& string) {
		this->push(string);
	}

	void adicionarNoInicio(const T& string) {
		this->unshift(string);
	}

	void adicionarNaPosicao(const T& string, int posicao) {
		this->push(posicao, string);
	}

	void adicionaEmOrdem(const T& string) {
		if (!this->isFull()) {
			int i;
			for (i = 0; i < this->length(); ++i)
				if (maior(this->m_array[i], string))
					break;
			this->push(i, string);
		}
	}

	T mostrar(int index) {
		return this->peek(index);
	}

	T retirar() {
		return this->pop();
	}

	T retirarDoInicio() {
		return this->shift();
	}

	T retirarDaPosicao(int index) {
		return this->pop(index);
	}

	T retirarEspecifico(const T& string) {
		for (int i = 0; i < this->length(); ++i)
			if (igual(this->m_array[i], string))
				return this->pop(i);
		throw NOT_FOUND_ERROR;
	}

	int &ultimo;

private:
	bool igual(const T& a, const T& b) {
		return strcmp(a, b) == 0;
	}

	bool maior(const T& a, const T& b) {
		return strcmp(a, b) > 0;
	}
};

#endif /* TLISTA_H_ */
