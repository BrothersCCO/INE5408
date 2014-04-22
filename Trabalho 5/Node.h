#ifndef NODE_H_
#define NODE_H_

template<class T>
class Node {
public:
	Node(const T&, const T*);
	virtual ~Node();
	bool operator==(const Node<T>*);
	bool operator<(const Node<T>*);

	Node<T> *getNext();
	void setNext(Node<T> *next);

private:
	T *value;
	Node<T> *next;
};

#endif /* NODE_H_ */
