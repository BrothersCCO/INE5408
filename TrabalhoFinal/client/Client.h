/*
 * Client.h
 *
 *  Created on: May 18, 2014
 *      Author: ranieri
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include "../structures/CircularlyLinkedList.h"
#include "ClientQueueBehavior.h"

enum ClientPaymentBehavior { CHECK, MONEY };

class Client {
	ClientPaymentBehavior paymentBehavior;
	ClientQueueBehavior* queueBehavior;

public:
	Client();
	Client(const ClientPaymentBehavior&, const ClientQueueBehavior&);
	virtual ~Client();

	void enterBestQueue(const QueueList&) const;
	int cartSize() const;
};

#endif /* CLIENT_H_ */
