#include "Node.h"

#include <iostream>

template<class T>
Node<T>::Node(T* value, Node<T>* next) {
	this->value = value;
	this->next = next;
}

template<class T>
Node<T>::~Node() {
	this->value = 0;
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
T *Node<T>::getItem() {
    return this->value;
}

template<class T>
Node<T> *Node<T>::getNext() {
	return this->next;
}

template<class T>
void Node<T>::setNext(Node<T> *next) {
	this->next = next;
}
