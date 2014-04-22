/*
 * Lancamento.h
 *
 *  Created on: Apr 21, 2014
 *      Author: ranieri
 */

#ifndef LANCAMENTO_H_
#define LANCAMENTO_H_

class Lancamento {
public:
    Lancamento();
	Lancamento(char*, double);
	virtual ~Lancamento();
	char* nome();
	double valor();
private:
	char *_nome;
	double _valor;
};

#endif /* LANCAMENTO_H_ */
