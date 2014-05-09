#include <iostream>
#include <stdexcept>

#ifndef CIRCULARLYLINKEDLIST_H_
#define CIRCULARLYLINKEDLIST_H_

template<typename T>
class CircularlyLinkedList {
	struct node {
		node(node *pred, node *succ, const T &item) :
				pred(pred), succ(succ), item(item) {
		}

		node *pred, *succ;
		T item;
	};

	/* wardddd */
	node *sentinel;
	int count;

public:
	CircularlyLinkedList() :
			sentinel(new node(sentinel, sentinel, T())), count(0) {
	}

	virtual ~CircularlyLinkedList() {
		while (sentinel->succ != sentinel) {
			this->sentinel->succ = this->sentinel->succ->succ;
			delete this->sentinel->succ->pred;
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
	void insert(int position, const T &item) {
		if (position == 0) {
			unshift(item);
			return;
		} else if (position == count) {
			push(item);
			return;
		} else if (position < 0 || position > count) {
			throw std::out_of_range("Inserting out of bounds");
		}

		node *aux = sentinel;
		for (int i = 0; i < position; ++i) {
			aux = aux->succ;
		}

		/*
		 * Mudar o predecessor do sucessor de aux ->
		 *** Sucessor do predecessor de aux aponta para novo item
		 *** Predecessor de aux aponta para novo item
		 * Tempo: O(1)
		 */
		aux->pred = aux->pred->succ = new node(aux->pred, aux, item);
		++count;
	}

	void push(const T& item) {
		/*
		 * Mudar o predecessor do sucessor da sentinela ->
		 *** Sucessor do predecessor da sentinela aponta para novo item
		 *** Predecessor da sentinela aponta para novo item
		 */
		sentinel->pred = sentinel->pred->succ = new node(sentinel->pred, sentinel, item);
		++this->count;
	}

	void unshift(const T& item) {
		/*
		 * Mudar o sucessor do predecessor da sentinela ->
		 *** Predecessor do sucessor da sentinela aponta para novo item
		 *** Sucessor da sentinela aponta para novo item
		 */
		sentinel->succ = sentinel->succ->pred = new node(sentinel, sentinel->succ, item);
		++this->count;
	}

	/**
	 * Operações de remoção
	 */
	/*T pop() {
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
	}*/

	class iterator {
	public:
		iterator(node *ptr) :
				ptr(ptr) {
		}

		iterator &operator=(const iterator &other) {
			if (!this == other) {
				return this(other);
			} else {
				return this;
			}
		}

		iterator &operator++() {
			this->ptr = this->ptr->succ;
			return *this;
		}

		iterator operator++(int) {
			iterator other(this);
			++this;
			return other;
		}

		iterator &operator--() {
			this->ptr = this->ptr->pred;
			return *this;
		}

		iterator operator--(int) {
			iterator other(this);
			--this;
			return other;
		}

		bool operator==(const iterator &other) const {
			return this->ptr == other.ptr;
		}

		bool operator!=(const iterator &other) const {
			return !(*this == other);
		}

		T &operator*() const {
			return this->ptr->item;
		}

		T *operator->() const {
			return this->ptr->item;
		}

	private:
		node *ptr;
	};

	iterator begin() {
		return iterator(this->sentinel->succ);
	}

	iterator end() {
		return iterator(this->sentinel);
	}

	iterator rbegin() {
		return iterator(this->sentinel->pred);
	}

	iterator rend() {
		return iterator(this->sentinel);
	}
}
;

#endif /* CIRCULARLYLINKEDLIST_H_ */
