/*
 * List.hpp
 *
 *  Created on: Apr 7, 2014
 *      Author: ranieri
 */

#ifndef LIST_HPP_
#define LIST_HPP_

#include <cstring>
#include "definitions.h"

template<typename T>
class List {
public:
	List(int size) :
			m_array(new T[size]), m_ptr(-1), m_size(size) {
	}

	void clear() {
		m_ptr = -1;
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

	bool isEmpty() {
		return length() == 0;
	}

	bool isFull() {
		return length() == m_size;
	}

	int length() {
		return m_ptr + 1;
	}

	T peek(int index) {
		if (index >= 0 && index < this->length()) {
			return this->m_array[index];
		}
		throw NOT_FOUND_ERROR;
	}

	T pop() {
		return this->pop(this->length() - 1);
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

	void push(T value) {
		this->push(this->length(), value);
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

	T shift() {
		return this->pop(0);
	}

	void unshift(T value) {
		push(0, value);
	}
protected:
	int find(const T& value) {
		for (int i = 0; i < this->length(); ++i)
			if (this->m_array[i] == value)
				return i;
		throw NOT_FOUND_ERROR;
	}

	void closeSpaceAt(int index) {
		if (!this->isEmpty()) {
			if (index >= 0 && index < this->length()) {
				--this->m_ptr;
				for (int i = index; i < this->length(); ++i)
					this->m_array[i] = this->m_array[i + 1];
			} else
				throw FORBIDDEN_ERROR;
		} else
			throw FULL_STRUCTURE_ERROR;
	}

	void openSpaceAt(int index) {
		if (!this->isFull()) {
			if (index >= 0 && index <= this->length()) {
				++this->m_ptr;
				for (int i = this->length(); i >= index; --i)
					this->m_array[i + 1] = this->m_array[i];
			} else
				throw FORBIDDEN_ERROR;
		} else
			throw FULL_STRUCTURE_ERROR;
	}

	T *m_array;
	int m_ptr, m_size;
};

#endif /* LIST_HPP_ */
