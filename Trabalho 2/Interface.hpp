/*
 * Interface.h
 *
 *  Created on: Apr 3, 2014
 *      Author: ranieri
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <stdio.h>
#include "definitions.h"
#include "Queue.hpp"

class Interface {
public:
	Interface(Queue<DataItem>* q) {
		m_queue = q;
	}
	~Interface() {
	}
	void run() {
		do {
			menu();
		} while (execute());
	}

	void menu() {
		std::cout << "Filas:" << std::endl
				<< "Digite o numero da opção desejada:" << std::endl
				<< "1) Enfileirar Elemento" << std::endl
				<< "2) Desenfileirar Elemento" << std::endl << "3) Limpar Fila"
				<< std::endl << "4) Mostrar Fila" << std::endl
				<< "5) Sair do programa" << std::endl;
	}

	bool execute() {
		int option;
		std::cin >> option;
		switch (option) {
		case 1:
			std::cout << "Digite uma string (sem espaços) a ser enfileirada:"
					<< std::endl;
			try {
				m_queue->push(input());
				std::cout << "String enfileirada corretamente." << std::endl;
			} catch (int &e) {
				if (e == FULL_STRUCTURE_ERROR) {
					std::cout << "Erro: fila cheia." << std::endl;
				} else if (e == INPUT_TOO_LARGE) {
					std::cout << "String muito grande para enfileirar."
							<< std::endl;
				}
			}
			break;
		case 2:
			std::cout << "Desenfileirando um valor:" << std::endl;
			try {
				DataItem value(m_queue->shift());
				std::cout << "Valor desenfileirando: " << value << std::endl;
			} catch (int &e) {
				if (e == EMPTY_STRUCTURE_ERROR) {
					std::cout << "Erro: fila vazia." << std::endl;
				}
			}
			break;
		case 3:
			m_queue->clear();
			std::cout << "Fila limpa." << std::endl;
			break;
		case 4:
			std::cout << "Posição\tValor" << std::endl;
			int s;
			s = m_queue->length();
			try {
				if (s > 0)
					for (int i = 0; i < s; ++i) {
						DataItem _ = (*m_queue)[i];
						std::cout << i << '\t' << *_.value() << std::endl;
					}
				else
					throw EMPTY_STRUCTURE_ERROR;
			} catch (int &e) {
				if (e == EMPTY_STRUCTURE_ERROR) {
					std::cout << "Erro: fila vazia." << std::endl;
				}
			}
			break;
		case 5:
			return false;
			break;
		default:
			std::cout << "Erro " << option << std::endl;
			return false;
		}
		return true;
	}

	DataItem input() {
		char input[40];
		std::cin >> *input;
		DataItem _(input);
		return _;
	}
private:
	Queue<DataItem> *m_queue;
};

#endif /* INTERFACE_H_ */
