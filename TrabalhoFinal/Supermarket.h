/*
 * Supermarket.h
 *
 *  Created on: May 18, 2014
 *      Author: ranieri
 */

#ifndef SUPERMARKET_H_
#define SUPERMARKET_H_

#include "structures/CircularlyLinkedList.h"
#include "CheckoutQueue.h"

class Supermarket {
	CircularlyLinkedList<CheckoutQueue> queues;

public:
	Supermarket(const CircularlyLinkedList<CheckoutQueue>&);
	virtual ~Supermarket();
};

#endif /* SUPERMARKET_H_ */
