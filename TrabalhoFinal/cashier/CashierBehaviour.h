/*
 * CashierBehaviour.h
 *
 *  Created on: May 19, 2014
 *      Author: ranieri
 */

#ifndef CASHIERBEHAVIOUR_H_
#define CASHIERBEHAVIOUR_H_

#include "../client/Client.h"

class CashierBehaviour {
public:
	CashierBehaviour();
	virtual ~CashierBehaviour();
	int process(const Client&);
};

#endif /* CASHIERBEHAVIOUR_H_ */
