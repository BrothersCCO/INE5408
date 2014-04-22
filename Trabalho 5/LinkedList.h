#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "Node.h"

typedef unsigned int size_type;
template<class T>
class LinkedList {
public:
	LinkedList();
	virtual ~LinkedList();

	size_type count();
	void destroy();
	bool empty();
	void insert(size_type, T*);
	T *pop();
	void push(T*);
	T *remove(size_type);
	T *shift();
	void unshift(T*);

	class iterator;
	iterator begin();
	iterator end();
private:
	Node<T> *head/*, *tail*/;
	size_type length;
};

template<class T>
class LinkedList<T>::iterator {
public:
	iterator(Node<T> *ptr);
	iterator &operator++();
	iterator operator++(const int);
	T &operator*();
	T *operator->();
	bool operator==(const iterator&);
	bool operator!=(const iterator&);
private:
	Node<T> *ptr;
};

#include "LinkedList.tpp"

#endif /* LINKEDLIST_H_ */
