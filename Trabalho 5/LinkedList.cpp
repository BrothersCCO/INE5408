#include "definitions.h"
#include "LinkedList.h"
#include "Node.h"

template<class T>
LinkedList<T>::LinkedList() {
	this->head/* = this->tail*/= this->length = 0;
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
void LinkedList<T>::insert(size_type position, const T& item) {
	if (position == 0) {
		this->unshift(item);
	} else if (position <= this->length + 1) {
		Node<T> *previous = this->head;
		for (size_type i = 1; i <= position; ++i) {
			previous = previous->next;
		}
		Node<T> *current = new Node<T>(item, previous->next);
		previous->next = current;
		++this->length;
	}
}

template<class T>
T &LinkedList<T>::pop() {
	return this->remove(this->length);
}

template<class T>
void LinkedList<T>::push(const T& item) {
	this->insert(this->length + 1, item);
}

template<class T>
T &LinkedList<T>::remove(size_type position) {
	if (!this->empty()) {
		if (position == 0) {
			return this->shift();
		} else if (position < this->length) {
			Node<T> *previous = this->head;
			for (size_type i = 1; i < position; ++i) {
				previous = previous->next;
			}
			T *_ = previous->next->item;
			previous->next = previous->next->next;
			--this->length;
			return _;
		}
	} else {
		throw EMPTY_STRUCTURE_ERROR;
	}
}

template<class T>
T &LinkedList<T>::shift() {
	if (!this->empty()) {
		T *_ = this->head->item;
		this->head = this->head->next;
		--this->length;
		return _;
	} else {
		throw EMPTY_STRUCTURE_ERROR;
	}
}

template<class T>
void LinkedList<T>::unshift(const T& item) {
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
	if (this->ptr->next != 0) {
		this->ptr = this->ptr->next;
	} else {
		throw NOT_FOUND_ERROR;
	}
}

template<class T>
typename LinkedList<T>::iterator LinkedList<T>::iterator::operator++(
		const int) {
	if (this->ptr->next != 0) {
		LinkedList<T>::iterator *_ = this->ptr;
		this->ptr = this->ptr->next;
		return _;
	} else {
		throw NOT_FOUND_ERROR;
	}
}

template<class T>
T &LinkedList<T>::iterator::operator*() {
	return this->ptr;
}

template<class T>
T *LinkedList<T>::iterator::operator->() {
	return this->ptr;
}

template<class T>
bool LinkedList<T>::iterator::operator==(const iterator& other) {
	return this->ptr == other.ptr;
}

template<class T>
bool LinkedList<T>::iterator::operator!=(const iterator& other) {
	return !(*this == other);
}
