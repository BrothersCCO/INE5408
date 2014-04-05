#ifndef DATAITEM_H_
#define DATAITEM_H_

#include <iostream>

template<typename T>
class DataItem {
public:
	DataItem() {
	}
	DataItem(T *value) {
		m_value = value;
	}
	virtual ~DataItem() {
	}

	void operator=(T value) {
		m_value = value;
	}

	/**
	 * Isso só existe porque no printf eu preciso do valor e não tem como sobrecarregar nada. (acho)
	 */
	T *value() {
		return m_value;
	}

	friend std::ostream& operator<<(std::ostream &out,
			const DataItem<T> &cDataItem) {
		out << cDataItem.m_value;
		return out;
	}
protected:
	T *m_value;
};

#endif /* DATAITEM_H_ */
