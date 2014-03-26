#include <iostream>
#include <stdio.h>
using namespace std;

const int ERROESTRUTURACHEIA = -1;
const int ERROESTRUTURAVAZIA = -2;

template<typename T>
class EstruturaLinear {
	public:
		T *m_vetor;
		int m_topo;
	
		EstruturaLinear(int tamanho) {
			m_vetor = new T[tamanho];
			m_tamanho = tamanho;
			m_topo = -1;
		}
		
		T topo() {
			if (m_topo >= 0) {
				return m_vetor[m_topo];
			} else {
				return ERROESTRUTURAVAZIA;
			}
		}
		
		T espiar(int pos) {
			if (pos >= 0 && pos <= m_topo) {
				return m_vetor[pos];
			}
		}
		
		int inserir(const T &item) {
			if (m_topo < m_tamanho - 1) {
				m_vetor[++m_topo] = item;
				return 0;
			} else {
				return ERROESTRUTURACHEIA;
			}
		}
		
		virtual T retirar() = 0;

		bool estaCheio() {
			return m_topo == m_tamanho - 1;
		}
		
		bool estaVazio() {
			return m_topo == -1;
		}
		
	protected:
		int m_tamanho;
};

class Pilha : public EstruturaLinear<int> {
	public:
		Pilha() : EstruturaLinear<int>(MAXPILHA) {
		}
		
		int retirar() {
			return m_vetor[m_topo--];
		}
		
	private:
		static const int MAXPILHA = 30;
};

Pilha *p;

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
			if (p->inserir(aux) != ERROESTRUTURACHEIA) {
				cout << "Valor empilhado corretamente." << endl;
			} else {
				cout << "Erro: pilha cheia." << endl;
			}
			break;
		case 2:
			cout << "Desempilhando um valor:" << endl;
			if (!p->estaVazio()) {
				aux = p->retirar();
				cout << "Valor desempilhado: " << aux << endl;
			} else {
				cout << "Erro: pilha vazia." << endl;
			}
			break;
		case 3:
			p = new Pilha();
			cout << "Pilha limpa." << endl;
			break;
		case 4:
			if (!p->estaVazio()) {
				cout << "Posição Valor" << endl;
				for (int i = 0; i <= p->m_topo; ++i) {
					printf("%7i %5i\n", i, p->m_vetor[i]);
				}
			} else {
				cout << "Erro: pilha vazia." << endl;
			}
			break;
		default: return 0; break;
	}
	return interface();
}

int main() {
	p = new Pilha();
	return interface();
}
