/*
 * CheckoutQueue.h
 *
 *  Created on: May 18, 2014
 *      Author: ranieri
 */

#ifndef CHECKOUTQUEUE_H_
#define CHECKOUTQUEUE_H_

#include "cashier/Cashier.h"
#include "structures/CircularlyLinkedList.h"
#include "client/Client.h"

class CheckoutQueue {
	Cashier cashier;
	CircularlyLinkedList<Client> queue;
	int servedClients;
	int totalIncome;

public:
	CheckoutQueue(const Cashier&);
	virtual ~CheckoutQueue();

	void enter(const Client&);
};

#endif /* CHECKOUTQUEUE_H_ */
