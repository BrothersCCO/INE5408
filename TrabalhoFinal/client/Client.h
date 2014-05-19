/*
 * Client.h
 *
 *  Created on: May 18, 2014
 *      Author: ranieri
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include "../structures/CircularlyLinkedList.h"

enum PaymentBehavior { CHECK, MONEY };
enum QueueBehavior { SHORTEST, SMALLEST };

class Client {
	PaymentBehavior pb;
	QueueBehavior qb;

public:
	Client();
	Client(const PaymentBehavior&, const QueueBehavior&);
	virtual ~Client();

	void enterBestQueue(const CircularlyLinkedList<Client>&);
};

#endif /* CLIENT_H_ */
