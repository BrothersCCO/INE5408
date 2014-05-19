/*
 * ClientFactory.h
 *
 *  Created on: May 18, 2014
 *      Author: ranieri
 */

#ifndef CLIENTFACTORY_H_
#define CLIENTFACTORY_H_

#include "Client.h"

class ClientFactory {
public:
	ClientFactory();
	virtual ~ClientFactory();

	Client create();
};

#endif /* CLIENTFACTORY_H_ */
