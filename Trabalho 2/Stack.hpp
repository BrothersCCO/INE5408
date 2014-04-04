#include "DataStructure.hpp"

#ifndef STACK_H_
#define STACK_H_

/**
 * empilhar = push (herdado)
 * desempilhar = pop (em filas seria shift)
 * topo = top
 *
 */
template<typename T>
class Stack: public DataStructure<T> {
public:
	Stack(int size) :
			DataStructure<T>(size) {
	}

	T peek() {
		if (!this->isEmpty()) {
			return this->m_array[this->m_ptr];
		} else {
			throw EMPTY_STRUCTURE_ERROR;
		}
	}

	T pop() {
		if (!this->isEmpty()) {
			return this->m_array[this->m_ptr--];
		} else {
			throw EMPTY_STRUCTURE_ERROR;
		}
	}
};
#endif
