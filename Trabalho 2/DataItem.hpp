#include "definitions.h"

#ifndef DATAITEM_HPP_
#define DATAITEM_HPP_

template<typename T>
class DataItem {
public:
	DataItem(T value) {
		m_value = value;
	}

	T get() {
		return m_value;
	}

	bool operator=(T value) {
		return m_value = value;
	}
protected:
	T *m_value;
};

#endif /* DATAITEM_HPP_ */
