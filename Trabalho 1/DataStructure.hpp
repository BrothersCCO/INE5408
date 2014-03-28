#ifndef DATASTRUCTURE_H_
#define DATASTRUCTURE_H_

#define FULL_STRUCTURE_ERROR 1
#define EMPTY_STRUCTURE_ERROR 2

template<typename T>
class DataStructure {
public:
	DataStructure(int size) {
		m_array = new T[size];
		m_size = size;
		clear();
	}

	~DataStructure() {
		delete [] m_array;
	}

	void clear() {
		m_ptr = -1;
	}

	void push(T item) {
		if (!isFull()) {
			m_array[++m_ptr] = item;
		} else {
			throw FULL_STRUCTURE_ERROR;
		}
	}

	int length() {
		return m_ptr + 1;
	}

	bool isFull() {
		return length() == m_size;
	}

	bool isEmpty() {
		return m_ptr == -1;
	}

	T& operator[](int i) {
		return m_array[i];
	}

protected:
	T *m_array;
	int m_ptr, m_size;
};

#endif /* DATASTRUCTURE_H_ */
