/*
 * ClientQueueBehavior.h
 *
 *  Created on: May 19, 2014
 *      Author: ranieri
 */

#ifndef CLIENTQUEUEBEHAVIOR_H_
#define CLIENTQUEUEBEHAVIOR_H_

#include "../CheckoutQueue.h"

typedef CircularlyLinkedList<CheckoutQueue> QueueList;

class ClientQueueBehavior {
	// esta classe é um singleton, não é possível instanciar ou copiar
	ClientQueueBehavior();
	ClientQueueBehavior(const ClientQueueBehavior&);
	ClientQueueBehavior& operator=(const ClientQueueBehavior&);

public:
	virtual ~ClientQueueBehavior();
	virtual static ClientQueueBehavior& getInstance() const = 0;
	virtual CheckoutQueue& search(const QueueList&) const = 0;
};

class FewerItems: public ClientQueueBehavior {
public:
	static ClientQueueBehavior& getInstance() const {
		static FewerItems instance;
		return instance;
	}

	CheckoutQueue& search(const QueueList& queues) const {
		bool leave = true;
		if (queues.length()) {
			QueueList::const_iterator best = queues.begin();
			for (QueueList::const_iterator it = best + 1; it != queues.end();
					++it) {
				if (it->length() < 10 && it->totalItems()) {

				}
			}
			return *best;
		}
		throw 0;
	}
};

class ShorterQueue: public ClientQueueBehavior {

};

#endif /* CLIENTQUEUEBEHAVIOR_H_ */
