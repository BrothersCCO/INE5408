/*
 * Supermarket.cpp
 *
 *  Created on: May 18, 2014
 *      Author: ranieri
 */

#include "Supermarket.h"
#include "structures/CircularlyLinkedList.h"

Supermarket::Supermarket(const CircularlyLinkedList<CheckoutQueue>& queues) :
		queues(queues) {

}

Supermarket::~Supermarket() {
	// TODO Auto-generated destructor stub
}

