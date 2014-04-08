/*
 * Queue.h
 *
 *  Created on: Apr 3, 2014
 *      Author: ranieri
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "DataStructure.hpp"

template<typename T>
class Queue: public virtual DataStructure<T> {
public:
	Queue(int size) :
			DataStructure<T>::DataStructure(size) {
	}
	virtual ~Queue() {
	}
	T shift() {
		if (!this->isEmpty()) {
			T _ = this->m_array[0];
			for (int i = 0; i < this->m_ptr; ++i)
				this->m_array[i] = this->m_array[i + 1];
			--this->m_ptr;
			return _;
		}
		throw EMPTY_STRUCTURE_ERROR;
	}
};

#endif /* QUEUE_H_ */
