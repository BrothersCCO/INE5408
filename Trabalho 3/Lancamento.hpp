/*
 * Lancamento.hpp
 *
 *  Created on: Apr 8, 2014
 *      Author: ranieri
 */

#ifndef LANCAMENTO_HPP_
#define LANCAMENTO_HPP_

#include <cstring>

class Lancamento {
public:
	Lancamento() {
	}

	Lancamento(char* nome, double valor) {
		m_nome = new char[strlen(nome) + 1];
		strcpy(m_nome, nome);
		m_valor = valor;
	}

	char* nome() {
		return m_nome;
	}

	double valor() {
		return m_valor;
	}
private:
	char* m_nome;
	double m_valor;
};

#endif /* LANCAMENTO_HPP_ */
