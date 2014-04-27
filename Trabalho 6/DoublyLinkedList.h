#include <iostream>
#include <exception>

#ifndef DOUBLYLINKEDLIST_H_
#define DOUBLYLINKEDLIST_H_

template<typename T>
class DoublyLinkedList {
	class node {
	public:
		node(node* pred, node* succ, const T& item) :
				pred(pred), succ(succ), item(item) {
		}

		~node() {
			delete &item;
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
		T removed = head->item;
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
			throw std::range_error("Index out of range");
		}
	}

	void push(const T& item) {
		if (this->count) {
			node* inserted = new node(this->tail, 0, item);
			this->tail->succ = inserted;
			this->tail = inserted;
			++this->count;
		} else {
			this->insertFirstNode(item);
		}
	}

	void unshift(const T& item) {
		if (this->count) {
			node* inserted = new node(0, this->head, item);
			this->head->pred = inserted;
			this->head = inserted;
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
			node* exTail = this->tail;
			this->tail = exTail->pred;
			this->tail->succ = 0;
			--this->count;
			return removed;
		} else if (this->count) {
			return this->removeOnlyNode();
		} else {
			throw std::range_error("Empty list.");
		}
	}

	T remove(int position) {
		if (position == 0) {
			return this->shift();
		} else if (position == this->count - 1) {
			return this->pop();
		} else if (position > 0 && position < this->count) {
			node* ex = this->head; // será o nó que estava na posição escolhida
			for (int i = 0; i < position; ++i) {
				ex = ex->succ;
			}
			T removed = ex->item;
			ex->pred->succ = ex->succ;
			ex->succ->pred = ex->pred;
			--this->count;
			return removed;
		}
	}

	T shift() {
		if (this->count > 1) {
			T removed = this->head->item;
			node* exHead = this->head;
			this->head = exHead->succ;
			this->head->pred = 0;
			--this->count;
			return removed;
		} else if (this->count) {
			return this->removeOnlyNode();
		} else {
			throw std::range_error("Empty list.");
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
