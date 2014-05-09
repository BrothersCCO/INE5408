#include <iostream>
#include <stdexcept>

#ifndef DOUBLYLINKEDLIST_H_
#define DOUBLYLINKEDLIST_H_

template<typename T>
class LinkedQueue {
	class node {
	public:
		node(node* succ, const T& item) :
				succ(succ), item(item) {
		}

		node* succ;
		T item;
	};

	node* head;
	int count;

public:
	LinkedQueue() :
			head(0), count(0) {
	}

	virtual ~LinkedQueue() {
		node* tmp = this->head;
		for (int i = 0; i < this->count; ++i) {
			tmp = this->head;
			this->head = this->head->succ;
			delete tmp;
		}
	}

	bool empty() const {
		return this->count == 0;
	}

	int length() const {
		return this->count;
	}

	/**
	 * Operações de inserção
	 */
	void push(const T& item) {
		if (this->count) {
			node* previous = this->head;
			while (previous->succ != 0) {
				previous = previous->succ;
			}
			previous->succ = new node(0, item);
		} else {
			this->head = new node(0, item);
		}
		++this->count;
	}

	/**
	 * Operações de remoção
	 */
	T shift() {
		if (this->count) {
			T removed = this->head->item;
			node* tmp = this->head;
			this->head = this->head->succ;
			delete tmp;
			--this->count;
			return removed;
		} else {
			throw std::out_of_range("Shifting from empty list");
		}
	}
};

#endif /* DOUBLYLINKEDLIST_H_ */
