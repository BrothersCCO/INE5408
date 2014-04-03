#include "DataItem.hpp"
#include "definitions.h"

#ifndef DATASTRUCTURE_H_
#define DATASTRUCTURE_H_

template<typename T>
class DataStructure {
public:
	DataStructure(int size) {
		//m_array = DataItem<T>[size]();
		m_size = size;
		clear();
	}

	~DataStructure() {
		delete[] m_array;
	}

	void clear() {
		m_ptr = -1;
	}

	void push(T item) {
		if (!isFull())
			m_array[++m_ptr] = new DataItem<T> (item);
		else
			throw FULL_STRUCTURE_ERROR;
	}

	int length() {
		return m_ptr + 1;
	}

	bool isFull() {
		return length() == m_size;
	}

	bool isEmpty() {
		return length() == 0;
	}

	T operator[](int i) {
		if (i >= 0 && i <= m_ptr)
			return m_array[i].get();
		throw NOT_FOUND_ERROR;
	}

protected:
	DataItem<T> m_array;
	int m_ptr, m_size;
};

#endif /* DATASTRUCTURE_H_ */
