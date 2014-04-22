#include "Node.h"

template<class T>
Node<T>::Node(const T& value, const T* next = 0) {
	this->value = value;
	this->next = next;
}

template<class T>
Node<T>::~Node() {
	delete this->value;
	this->next = 0;
}

template<class T>
bool Node<T>::operator==(const Node<T>* cLinkedListItem) {
	return *(this->value) == *(cLinkedListItem->value);
}

template<class T>
bool Node<T>::operator<(const Node<T>* cLinkedListItem) {
	return *(this->value) < *(cLinkedListItem->value);
}

template<class T>
Node<T> *Node<T>::getNext() {
	return this->next;
}

template<class T>
void Node<T>::setNext(Node<T> *next) {
	this->next = next;
}
