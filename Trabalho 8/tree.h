#ifndef TREE_H_
#define TREE_H_

#include "list.h"

template<typename T, template<typename> class Container = list>
class tree {
protected:
	typedef unsigned int size_t;

public:
	virtual ~tree() {};

	virtual bool has(const T& item) const = 0;
	virtual size_t size() const = 0;

	virtual void insert(const T& item) = 0;
	virtual void remove(const T& item) = 0;

	virtual Container<T> in_order() const = 0;
	virtual Container<T> pre_order() const = 0;
	virtual Container<T> post_order() const = 0;
};

#endif /* TREE_H_ */
