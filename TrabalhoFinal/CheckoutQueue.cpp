/*
 * CheckoutQueue.cpp
 *
 *  Created on: May 18, 2014
 *      Author: ranieri
 */

#include "CheckoutQueue.h"
#include "cashier/Cashier.h"
#include "client/Client.h"

CheckoutQueue::CheckoutQueue(const Cashier& cashier) :
		cashier(cashier), servedClients(), totalIncome() {
}

CheckoutQueue::~CheckoutQueue() {
	// TODO Auto-generated destructor stub
}

void CheckoutQueue::enter(const Client& client) {
	queue.push_back(client);
}
