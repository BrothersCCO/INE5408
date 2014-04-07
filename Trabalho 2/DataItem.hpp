#ifndef DATAITEM_H_
#define DATAITEM_H_

#include <iostream>
#include <cstring>

class DataItem {
public:
	DataItem() {
	}

	DataItem(const char* value) {
		strcpy(m_value, value);
	}

	const char *value() {
		return m_value;
	}

	void operator=(DataItem &cDataItem) {
		strcpy(m_value, cDataItem.value());
	}

	friend std::ostream& operator<<(std::ostream &out, DataItem &cDataItem) {
		out << cDataItem.value();
		return out;
	}
protected:
	char m_value[40];
};

#endif /* DATAITEM_H_ */
