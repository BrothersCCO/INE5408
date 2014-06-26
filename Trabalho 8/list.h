#ifndef LIST_H_
#define LIST_H_

#include <algorithm>
#include <stdexcept>

template<typename T>
class list {
private:
	struct node {
	public:
		node(node* pred, node* succ, const T& item) :
				_pred(pred), _succ(succ), _item(item) {
		}

		node* _pred;
		node* _succ;
		T _item;
	};

	template<typename NodeT>
	class iterator_base {
	public:
		iterator_base(node* ptr) :
				_ptr(ptr) {
		}

		iterator_base& operator=(iterator_base<NodeT> other) {
		  std::swap(*this, other);
			return *this;
		}

		iterator_base& operator++() {
			if (_ptr == 0)
				throw std::out_of_range("Iterating beyond list end.");
			_ptr = _ptr->_succ;
			return *this;
		}

		iterator_base operator++(int) {
			node* old = _ptr;
			++(*this);
			return iterator_base<NodeT>(old);
		}

		iterator_base& operator--() {
			if (_ptr == 0)
				throw std::out_of_range("Iterating beyond list begin.");
			_ptr = _ptr->_pred;
			return *this;
		}

		iterator_base operator--(int) {
			node* old = _ptr;
			--(*this);
			return iterator_base<NodeT>(old);
		}

		bool operator==(const iterator_base<NodeT>& other) const {
			return _ptr == other._ptr;
		}

		bool operator!=(const iterator_base<NodeT>& other) const {
			return _ptr != other._ptr;
		}

		NodeT& operator*() const {
			return _ptr->_item;
		}

		NodeT* operator->() const {
			return &(_ptr->_item);
		}
		
		friend void swap(iterator_base<NodeT>& a, iterator_base<NodeT>& b) {
		  std::swap(a._ptr, b._ptr);
		}

	private:
		node* _ptr;
	};

public:
	list() :
			_front(0), _back(0), _size(0) {
	}

	list(const list<T>& other) :
  	_front(0), _back(0), _size(0) {
		for (list<T>::const_iterator it = other.cbegin(); it != other.cend(); ++it)
			push_back(*it);
	}

	~list() {
		node* old;
		while (_front != 0) {
			old = _front;
			_front = _front->_succ;
			delete old;
		}
	}

	T at(size_t position) const {
		if (position < 0 || position >= this->_size)
			throw std::out_of_range("Out of range access.");

		node* p;
		if (position < (_size >> 1)) {
			p = _front;
			for (int i = 0; i < position; ++i)
				p = p->_succ;
		} else {
			p = _back;
			for (int i = _size - 1; i > position; --i)
				p = p->_pred;
		}
		return p->_item;
	}

	T back() const {
		empty_check();

		return _back->_item;
	}

	T front() const {
		empty_check();

		return _front->_item;
	}

	size_t size() const {
		return this->_size;
	}

	/**< Removal operations */
	T pop(size_t position) {
		if (position < 0 || position >= _size)
			throw std::out_of_range("Empty list.");

		if (position == 0)
			return pop_front();

		if (position == _size - 1)
			return pop_back();

		node* p;
		if (position < (_size >> 1)) {
			p = _front;
			for (int i = 0; i < position; ++i)
				p = p->_succ;
		} else {
			p = _back;
			for (int i = _size - 1; i > position; --i)
				p = p->_pred;
		}

		/**< Hold node, advance it and then delete the old one */
		T value(p->_item);
		p->_pred->_succ = p->_succ;
		p->_succ->_pred = p->_pred;
		delete p;

		--this->_size;
		return value;
	}

	T pop_back() {
		empty_check();

		node* aux = _back;
		T item(_back->_item);
		_back = _back->_pred;
		if (_back == 0) {
			_front = 0;
		} else {
			_back->_succ = 0;
		}
		delete aux;

		--this->_size;
		return item;
	}

	T pop_front() {
		empty_check();

		/**< Hold head, advance it and then delete the old one */
		node* aux = _front;
		T item(aux->_item);
		_front = _front->_succ;
		if (_front == 0) {
			_back = 0;
		} else {
			_front->_pred = 0;
		}
		delete aux;

		--this->_size;
		return item;
	}

	/**< Insertion operations */
	void push(size_t position, const T& item) {
		if (position < 0 || position > this->_size)
			throw std::out_of_range("Out of range access.");

		if (position == 0) {
			push_front(item);
			return;
		}

		if (position == this->_size) {
			push_back(item);
			return;
		}

		node* p;
		if (position < (_size >> 1)) {
			p = _front;
			for (int i = 0; i < position; ++i)
				p = p->_succ;
		} else {
			p = _back;
			for (int i = _size - 1; i > position; --i)
				p = p->_pred;
		}
		p->_pred = p->_pred->_succ = new node(p->_pred, p, item);
		++this->_size;
	}

	void push_back(const T& item) {
		if (!_size) {
			_front = _back = new node(0, 0, item);
		} else {
			_back = _back->_succ = new node(_back, 0, item);
		}
		++this->_size;
	}

	void push_front(const T& item) {
		if (!_size) {
			_front = _back = new node(0, 0, item);
		} else {
			_front = _front->_pred = new node(0, _front, item);
		}
		++this->_size;
	}

	typedef iterator_base<T> iterator;

	iterator begin() {
		return iterator(_front);
	}

	iterator end() {
		return iterator(0);
	}

	iterator rbegin() {
		return iterator(_back);
	}

	iterator rend() {
		return iterator(0);
	}

	typedef iterator_base<const T> const_iterator;

	const_iterator cbegin() const {
		return const_iterator(_front);
	}

	const_iterator cend() const {
		return const_iterator(0);
	}

	const_iterator crbegin() const {
		return const_iterator(_back);
	}

	const_iterator crend() const {
		return const_iterator(0);
	}

	list<T>& operator=(list<T> rhs) {
		swap(*this, rhs);
		return *this;
	}

	bool operator==(const list<T>& rhs) const {
		if (_size == rhs.size()) {
			for (const_iterator a = begin(), b = rhs.begin();
					a != end() && b != rhs.end(); ++a, ++b)
				if (*a != *b)
					return false;
			return true;
		}
		return false;
	}

	bool operator!=(const list<T>& rhs) const {
		return !(*this == rhs);
	}

	friend void swap(list<T>& a, list<T>& b) {
		using std::swap;

		swap(a._front, b._front);
		swap(a._back, b._back);
		swap(a._size, b._size);
	}

private:
	void empty_check() const {
		if (!_size)
			throw std::out_of_range("Empty list.");
	}

	node* _front;
	node* _back;
	size_t _size;
};

#endif /* LIST_H_ */
