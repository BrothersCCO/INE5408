#ifndef NODE_H_
#define NODE_H_

template<class T>
class Node {
public:
	Node(T*, Node<T>*);
	virtual ~Node();
	bool operator==(const Node<T>*);
	bool operator<(const Node<T>*);

    T *getItem();
	Node<T> *getNext();
	void setNext(Node<T> *next);

private:
	T *value;
	Node<T> *next;
};

#include "Node.tpp"

#endif /* NODE_H_ */
