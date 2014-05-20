/*
 * ClientFactory.cpp
 *
 *  Created on: May 18, 2014
 *      Author: ranieri
 */

#include "ClientFactory.h"
#include "Client.h"

ClientFactory::ClientFactory() {
	// TODO Auto-generated constructor stub

}

ClientFactory::~ClientFactory() {
	// TODO Auto-generated destructor stub
}

Client ClientFactory::create() {
	PaymentBehavior* pb = rand() % 5 ? &money : &check;
	QueueBehavior* qb = rand() % 2 ? &fewerItems : &shorterQueue;

	return Client(pb, qb);
}

