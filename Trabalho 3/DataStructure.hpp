/*
 * DataStructure.h
 *
 *  Created on: Apr 3, 2014
 *      Author: ranieri
 */

#ifndef DATASTRUCTURE_H_
#define DATASTRUCTURE_H_

#include "definitions.h"

template<typename T>
class DataStructure {
public:
	DataStructure(int size) {
		m_array = new T[size];
		m_size = size;
		clear();
	}

	~DataStructure() {
	}

	void clear() {
		m_ptr = -1;
	}

	T peek() {
		if (!isEmpty())
			return m_array[m_ptr];
		throw EMPTY_STRUCTURE_ERROR;
	}

	void push(T item) {
		if (!isFull()) {
			++m_ptr;
			m_array[m_ptr] = item;
		} else
			throw FULL_STRUCTURE_ERROR;
	}

	int length() {
		return m_ptr + 1;
	}

	bool isEmpty() {
		return length() == 0;
	}

	bool isFull() {
		return length() == m_size;
	}

	T operator[](int i) {
		if (i >= 0 && i <= m_ptr)
			return m_array[i];
		throw NOT_FOUND_ERROR;
	}

protected:
	T *m_array;
	int m_ptr, m_size;
};

#endif /* DATASTRUCTURE_H_ */
