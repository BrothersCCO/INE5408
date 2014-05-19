/*
 * Client.cpp
 *
 *  Created on: May 18, 2014
 *      Author: ranieri
 */

#include "Client.h"

Client::Client() :
		pb(), qb() {
}

Client::Client(const PaymentBehavior& pb, const QueueBehavior& qb) :
		pb(pb), qb(qb) {
}

Client::~Client() {
	// TODO Auto-generated destructor stub
}
