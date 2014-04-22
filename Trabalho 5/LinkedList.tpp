#include "definitions.h"
#include "LinkedList.h"
#include "Node.h"

template<class T>
LinkedList<T>::LinkedList() {
	this->head = 0;
    this->length = 0;
}

template<class T>
LinkedList<T>::~LinkedList() {
	while (!this->empty()) {
		delete this->shift();
	}
}

template<class T>
unsigned int LinkedList<T>::count() {
	return this->length;
}

template<class T>
void LinkedList<T>::destroy() {
	return this->~LinkedList();
}

template<class T>
bool LinkedList<T>::empty() {
	return this->length == 0;
}

template<class T>
void LinkedList<T>::insert(size_type position, T* item) {
	if (position == 0) {
		this->unshift(item);
	} else if (position < this->length + 1) {
		Node<T> *previous = this->head;
		for (size_type i = 1; i < position; ++i) {
			previous = previous->getNext();
		}
		Node<T> *current = new Node<T>(item, previous->getNext());
		previous->setNext(current);
		++this->length;
	}
}

template<class T>
T *LinkedList<T>::pop() {
	return this->remove(this->length - 1);
}

template<class T>
void LinkedList<T>::push(T* item) {
	this->insert(this->length, item);
}

template<class T>
T *LinkedList<T>::remove(size_type position) {
	if (!this->empty()) {
		if (position == 0) {
			return this->shift();
		} else if (position < this->length) {
			Node<T> *previous = this->head;
			for (size_type i = 1; i < position; ++i) {
				previous = previous->getNext();
			}
			T *_ = previous->getNext()->getItem();
			previous->setNext(previous->getNext()->getNext());
			--this->length;
			return _;
		}
	} else {
		throw EMPTY_STRUCTURE_ERROR;
	}
}

template<class T>
T *LinkedList<T>::shift() {
	if (!this->empty()) {
		T *_ = this->head->getItem();
		this->head = this->head->getNext();
		--this->length;
		return _;
	} else {
		throw EMPTY_STRUCTURE_ERROR;
	}
}

template<class T>
void LinkedList<T>::unshift(T* item) {
	Node<T> *current = new Node<T>(item, this->head);
	this->head = current;
	++this->length;
}

template<class T>
typename LinkedList<T>::iterator LinkedList<T>::begin() {
	return LinkedList<T>::iterator(this->head);
}

template<class T>
typename LinkedList<T>::iterator LinkedList<T>::end() {
	return LinkedList<T>::iterator(0);
}

template<class T>
LinkedList<T>::iterator::iterator(Node<T> *ptr) {
	this->ptr = ptr;
}

template<class T>
typename LinkedList<T>::iterator& LinkedList<T>::iterator::operator++() {
	if (this->ptr != 0) {
		this->ptr = this->ptr->getNext();
        return *this;
	} else {
		throw NOT_FOUND_ERROR;
	}
}

template<class T>
typename LinkedList<T>::iterator LinkedList<T>::iterator::operator++(
		const int) {
	if (this->ptr != 0) {
		LinkedList<T>::iterator *_ = this->ptr;
		this->ptr = this->ptr->getNext();
		return _;
	} else {
		throw NOT_FOUND_ERROR;
	}
}

template<class T>
T &LinkedList<T>::iterator::operator*() {
	return this->ptr->getItem();
}

template<class T>
T *LinkedList<T>::iterator::operator->() {
	return this->ptr->getItem();
}

template<class T>
bool LinkedList<T>::iterator::operator==(const iterator& other) {
	return this->ptr == other.ptr;
}

template<class T>
bool LinkedList<T>::iterator::operator!=(const iterator& other) {
	return !(*this == other);
}
