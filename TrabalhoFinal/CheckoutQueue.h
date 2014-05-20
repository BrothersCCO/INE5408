/*
 * CheckoutQueue.h
 *
 *  Created on: May 18, 2014
 *      Author: ranieri
 */

#ifndef CHECKOUTQUEUE_H_
#define CHECKOUTQUEUE_H_

#include "structures/CircularlyLinkedList.h"
#include "cashier/Cashier.h"
#include "client/Client.h"

typedef CircularlyLinkedList<Client> ClientList;

class CheckoutQueue {
	Cashier cashier;
	ClientList queue;
	int servedClients;
	int totalIncome;

public:
	CheckoutQueue(const Cashier&);
	virtual ~CheckoutQueue();

	void enter(const Client&) const;
	int length() const;
	int totalItems() const;
};

#endif /* CHECKOUTQUEUE_H_ */
