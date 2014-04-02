#include <iostream>
#include <stdio.h>
#include "Stack.hpp"

#define MAXPILHA 30

using namespace std;

Stack<int> *stack;

int interface() {
	cout << "Pilhas:" << endl
		 << "Digite o numero da opção desejada:" << endl
		 << "1) Empilhar Elemento" << endl
		 << "2) Desempilhar Elemento" << endl
		 << "3) Limpar Pilha" << endl
		 << "4) Mostrar Pilha" << endl
		 << "5) Sair do programa" << endl;
	int input, aux;
	cin >> input;
	switch (input) {
	case 1:
		cout << "Digite o elemento a ser empilhado:" << endl;
		cin >> aux;
		try {
			stack->push(aux);
			cout << "Valor empilhado corretamente." << endl;
		} catch (int e) {
			if (e == FULL_STRUCTURE_ERROR)
				cout << "Erro: pilha cheia." << endl;
		}
		break;
	case 2:
		cout << "Desempilhando um valor:" << endl;
		try {
			aux = stack->pop();
			cout << "Valor desempilhado: " << aux << endl;
		} catch (int e) {
			if (e == EMPTY_STRUCTURE_ERROR)
				cout << "Erro: pilha vazia." << endl;
		}
		break;
	case 3:
		stack->clear();
		cout << "Pilha limpa." << endl;
		break;
	case 4:
		try {
			cout << "Posição  Valor" << endl;
			int s = stack->length();
			if (s > 0)
				for (int i = 0; i < s; ++i)
					printf("%3i %10i\n", i, (*stack)[i]);
			else
				throw EMPTY_STRUCTURE_ERROR;
		} catch (int e) {
			if (e == EMPTY_STRUCTURE_ERROR)
				cout << "Erro: pilha vazia." << endl;
		}
		break;
	default:
		return 0;
		break;
	}
	return interface();
}

int main() {
	stack = new Stack<int>(MAXPILHA);
	return interface();
}
