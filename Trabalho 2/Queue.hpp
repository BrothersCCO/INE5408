#include "DataStructure.hpp"

#ifndef QUEUE_H_
#define QUEUE_H_

template<typename T>
class Queue: public DataStructure<T> {
public:
	Queue(int size) :
			DataStructure<T>(size) {
	}

	T *shift() {
		if (!this->isEmpty()) {
			T *item = this->m_array[0].get();
			for (int i = 0; i < this->m_ptr; ++i)
				this->m_array[i] = this->m_array[i + 1];
			--this->m_ptr;
			return item;
		} else
			throw EMPTY_STRUCTURE_ERROR;
	}
};
#endif
