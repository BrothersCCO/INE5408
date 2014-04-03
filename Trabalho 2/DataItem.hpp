#include "definitions.h"

#ifndef DATAITEM_HPP_
#define DATAITEM_HPP_

template<typename T>
class DataItem {
public:
	DataItem() {
	}

	DataItem(T value) {
		m_value = value;
	}

	T get() {
		return m_value;
	}

	void operator=(DataItem<T> value) {
		m_value = value.get();
	}
protected:
	T m_value;
};

#endif /* DATAITEM_HPP_ */
