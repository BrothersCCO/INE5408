/*
 * Client.cpp
 *
 *  Created on: May 18, 2014
 *      Author: ranieri
 */

#include "Client.h"

Client::Client(const ClientPaymentBehavior& paymentBehavior,
		const ClientQueueBehavior& queueBehavior) :
		paymentBehavior(paymentBehavior), queueBehavior(
				&queueBehavior.getInstance()) {
}

Client::~Client() {
	// TODO Auto-generated destructor stub
}
