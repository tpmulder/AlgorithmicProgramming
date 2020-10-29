#pragma once
#ifndef SUPERARRAY_H
#define SUPERARRAY_H

class IndexOutOfBoundsException : public std::exception { };

template <typename T>

class SuperArray {
private:
	T* _ptr{ nullptr };
	int _size{ 0 };
public:
	SuperArray() = default;

	explicit SuperArray(int size) {
		if (size != 0) {
			_ptr = new int[size] {};
			_size = size;
		}
	}

	~SuperArray() {
		delete[] _ptr;
	}

	int size() const {
		return _size;
	}

	bool isEmpty() const {
		return (_size == 0);
	}

	bool isValidIndex(int index) const {
		return (index >= 0) && (index < _size);
	}

	int& operator[](int index) {
		if (!IsValidIndex) {
			throw IndexOutOfBoundsException("");
		}
		return _ptr[index];
	}

	int operator[](int index) const {
		return _ptr[index];
	}
};

#endif