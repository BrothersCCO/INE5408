/*
 * ClientFactory.h
 *
 *  Created on: May 18, 2014
 *      Author: ranieri
 */

#ifndef CLIENTFACTORY_H_
#define CLIENTFACTORY_H_

#include "Client.h"
#include "behavior/PaymentBehavior.h"
#include "behavior/PaymentCheck.h"
#include "behavior/PaymentMoney.h"
#include "behavior/QueueBehavior.h"
#include "behavior/QueueFewerItems.h"
#include "behavior/QueueShorterQueue.h"

class ClientFactory {
public:
	ClientFactory();
	virtual ~ClientFactory();

	Client create();

private:
	const static PaymentCheck check();
	const static PaymentMoney money();
	const static QueueFewerItems fewerItems();
	const static QueueShorterQueue shorterQueue();
};

#endif /* CLIENTFACTORY_H_ */
