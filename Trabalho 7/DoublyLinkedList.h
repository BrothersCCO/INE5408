#include <iostream>
#include <stdexcept>

#ifndef DOUBLYLINKEDLIST_H_
#define DOUBLYLINKEDLIST_H_

template<typename T>
class DoublyLinkedList {
	class node {
	public:
		node(node* pred, node* succ, const T& item) :
				pred(pred), succ(succ), item(item) {
		}

		node* pred;
		node* succ;
		T item;
	};

	void insertFirstNode(const T& item) {
		this->head = this->tail = new node(0, 0, item);
		++this->count;
	}

	T removeOnlyNode() {
		T removed = this->head->item;
		delete this->head;
		this->head = this->tail = 0;
		--this->count;
		return removed;
	}

	node* head;
	node* tail;
	int count;

public:
	DoublyLinkedList() :
			head(0), tail(0), count(0) {
	}

	virtual ~DoublyLinkedList() {
		node* aux = this->head;
		for (int i = 0; i < this->count; ++i) {
			aux = this->head;
			this->head = this->head->succ;
			delete aux;
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
	void insert(int position, const T& item) {
		if (position == 0 || !count) {
			this->unshift(item);
		} else if (position == this->count) {
			this->push(item);
		} else if (position > 0 && position < this->count) {
			node* exNode = this->head; // será o nó que estava na posição escolhida
			for (int i = 0; i < position; ++i) {
				exNode = exNode->succ;
			}
			node* inserted = new node(exNode->pred, exNode, item);
			exNode->pred->succ = inserted;
			exNode->pred = inserted;
			++this->count;
		} else {
			throw std::out_of_range("Index out of range");
		}
	}

	void push(const T& item) {
		if (this->count) {
			this->tail = new node(this->tail, 0, item);
			this->tail->pred->succ = this->tail;
			++this->count;
		} else {
			this->insertFirstNode(item);
		}
	}

	void unshift(const T& item) {
		if (this->count) {
			this->head = new node(0, this->head, item);
			this->head->succ->pred = this->head;
			++this->count;
		} else {
			this->insertFirstNode(item);
		}
	}

	/**
	 * Operações de remoção
	 */
	T pop() {
		if (this->count > 1) {
			T removed = this->tail->item;
			this->tail = this->tail->pred;
			delete this->tail->succ;
			this->tail->succ = 0;
			--this->count;
			return removed;
		} else if (this->count) {
			return this->removeOnlyNode();
		} else {
			throw std::out_of_range("Empty list.");
		}
	}

	T remove(int position) {
		if (position == 0) {
			return this->shift();
		} else if (position == this->count - 1) {
			return this->pop();
		} else if (position < 0 && position >= this->count) {
			throw std::out_of_range("Invalid position.");
		}
		node* exNode = this->head; // será o nó que estava na posição escolhida
		for (int i = 0; i < position; ++i) {
			exNode = exNode->succ;
		}
		T removed = exNode->item;
		exNode->pred->succ = exNode->succ;
		exNode->succ->pred = exNode->pred;
		delete exNode;
		--this->count;
		return removed;
	}

	T shift() {
		if (this->count == 0) {
			throw std::out_of_range("Empty list.");
		} else if (this->count > 1) {
			T removed = this->head->item;
			this->head = this->head->succ;
			delete this->head->pred;
			this->head->pred = 0;
			--this->count;
			return removed;
		} else {
			return this->removeOnlyNode();
		}
	}

	class iterator {
	public:
		iterator(node* ptr) :
				ptr(ptr) {
		}

		iterator& operator=(const iterator& other) {
			if (!this == other) {
				return this(other);
			} else {
				return this;
			}
		}

		iterator& operator++() {
			this->ptr = this->ptr->succ;
			return *this;
		}

		iterator operator++(int) {
			iterator other(this);
			++this;
			return other;
		}

		iterator& operator--() {
			this->ptr = this->ptr->pred;
			return *this;
		}

		iterator operator--(int) {
			iterator other(this);
			--this;
			return other;
		}

		bool operator==(const iterator& other) const {
			return this->ptr == other.ptr;
		}

		bool operator!=(const iterator& other) const {
			return !(*this == other);
		}

		T& operator*() const {
			return this->ptr->item;
		}

		T* operator->() const {
			return this->ptr->item;
		}

	private:
		node* ptr;
	};

	iterator begin() {
		return iterator(this->head);
	}

	iterator end() {
		return iterator(this->tail->succ);
	}

	iterator rbegin() {
		return iterator(this->tail);
	}

	iterator rend() {
		return iterator(this->head->pred);
	}
};

#endif /* DOUBLYLINKEDLIST_H_ */
