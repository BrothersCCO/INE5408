#include <iostream>
#include <stdio.h>
#include "Queue.hpp"
#include "definitions.h"

#define MAXFILA 100

using namespace std;

Queue<char*[40]> *queue;

int interface() {
	cout << "Filas:" << endl
		 << "Digite o numero da opção desejada:" << endl
		 << "1) Enfileirar Elemento" << endl
		 << "2) Desenfileirar Elemento" << endl
		 << "3) Limpar Fila" << endl
		 << "4) Mostrar Fila" << endl
		 << "5) Sair do programa" << endl;
	int input;
	char *aux[40];
	cin >> input;
	switch (input) {
	case 1:
		cout << "Digite o elemento a ser enfileirado:" << endl;
		cin >> *aux;
		try {
			queue->push(&aux);
			cout << "Valor enfileirado corretamente." << endl;
		} catch (int e) {
			if (e == FULL_STRUCTURE_ERROR)
				cout << "Erro: fila cheia." << endl;
		}
		break;
	case 2:
		cout << "Desenfileirando um valor:" << endl;
		cout << queue->shift() << endl;
		/*try {
			aux = queue->shift();
			cout << "Valor desenfileirado: " << aux << endl;
		} catch (int e) {
			if (e == EMPTY_STRUCTURE_ERROR)
				cout << "Erro: fila vazia." << endl;
		}*/
		break;
	case 3:
		queue->clear();
		cout << "Fila limpa." << endl;
		break;
	case 4:
		try {
			cout << "Posição  Valor" << endl;
			int s = queue->length();
			if (s > 0)
				for (int i = 0; i < s; ++i)
					printf("%3i %s\n", i, (*queue)[i]);
			else
				throw EMPTY_STRUCTURE_ERROR;
		} catch (int e) {
			if (e == EMPTY_STRUCTURE_ERROR)
				cout << "Erro: fila vazia." << endl;
		}
		break;
	default:
		return 0;
		break;
	}
	return interface();
}

int main() {
	queue = new Queue<char*[40]>(MAXFILA);
	return interface();
}
