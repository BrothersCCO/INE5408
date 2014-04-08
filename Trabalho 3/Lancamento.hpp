/*
 * Lancamento.hpp
 *
 *  Created on: Apr 8, 2014
 *      Author: ranieri
 */

#ifndef LANCAMENTO_HPP_
#define LANCAMENTO_HPP_

class Lancamento {
public:
	Lancamento() {
		this->m_nome = new char[0];
		this->m_valor = 0.0;
	}

	Lancamento(char* nome, double valor) {
		this->m_nome = nome;
		this->m_valor = valor;
	}

	char* nome() {
		return this->m_nome;
	}

	double valor() {
		return this->m_valor;
	}
private:
	char* m_nome;
	double m_valor;
};

#endif /* LANCAMENTO_HPP_ */
