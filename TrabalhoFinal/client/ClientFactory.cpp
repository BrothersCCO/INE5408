/*
 * ClientFactory.cpp
 *
 *  Created on: May 18, 2014
 *      Author: ranieri
 */

#include "ClientFactory.h"
#include "Client.h"
#include <cstdlib>

ClientFactory::ClientFactory() {
	// TODO Auto-generated constructor stub

}

ClientFactory::~ClientFactory() {
	// TODO Auto-generated destructor stub
}

Client ClientFactory::create() {
	PaymentBehavior pb = MONEY;
	if (rand() % 10 < 2) {
		pb = CHECK;
	}

	QueueBehavior qb = SMALLEST;
	// TODO: shortest?

	return Client(pb, qb);
}

