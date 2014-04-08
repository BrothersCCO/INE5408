/*
 * List.hpp
 *
 *  Created on: Apr 7, 2014
 *      Author: ranieri
 */

#ifndef LIST_HPP_
#define LIST_HPP_

#include "definitions.h"
#include "Queue.hpp"
#include "Stack.hpp"

template<typename T>
class List: public Stack<T>, public Queue<T> {
public:
	List(int size) :
			DataStructure<T>::DataStructure(size), Stack<T>::Stack(size), Queue<T>::Queue(size) {
	}

	bool has(T value) {
		try {
			find(value);
			return true;
		} catch (int &e) {
			if (e == NOT_FOUND_ERROR)
				return false;
			throw e;
		}
	}

	T peek(int index) {
		if (index >= 0 && index <= this->m_ptr)
			return this->m_array[index];
		throw NOT_FOUND_ERROR;
	}

	T pop(int index) {
		if (index >= 0 && index <= this->m_ptr) {
			T tmp = this->m_array[index];
			closeSpaceAt(index);
			return tmp;
		}
		throw NOT_FOUND_ERROR;
	}

	T popValue(T value) {
		return pop(find(value));
	}

	void push(int index, T value) {
		openSpaceAt(index);
		this->m_array[index] = value;
	}

	void pushOrdered(T value) {
		if (!this->isFull()) {
			int i;
			for (i = 0; i <= this->m_ptr; ++i)
				if (this->m_array[i] < value)
					break;
			push(i, value);
		}
	}

	void unshift(T value) {
		push(0, value);
	}
private:
	int find(T value) {
		for (int i = 0; i <= this->m_ptr; ++i)
			if (this->m_array[i] == value)
				return i;
		throw NOT_FOUND_ERROR;
	}

	void closeSpaceAt(int index) {
		if (!this->isEmpty()) {
			if (index >= 0 && index <= this->m_ptr) {
				--this->m_ptr;
				for (int i = index; i < this->m_ptr; ++i)
					this->m_array[i] = this->m_array[i + 1];
			} else
				throw FORBIDDEN_ERROR;
		} else
			throw FULL_STRUCTURE_ERROR;
	}

	void openSpaceAt(int index) {
		if (!this->isFull()) {
			if (index >= 0 && index <= this->m_ptr) {
				++this->m_ptr;
				for (int i = index; i < this->m_ptr; ++i)
					this->m_array[i + 1] = this->m_array[i];
			} else
				throw FORBIDDEN_ERROR;
		} else
			throw FULL_STRUCTURE_ERROR;
	}
};

#endif /* LIST_HPP_ */
