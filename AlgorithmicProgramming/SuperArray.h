#pragma once
#ifndef SUPERARRAY_H
#define SUPERARRAY_H

#include <iostream>

class IndexOutOfBoundsException : public std::exception { };

template <typename T>
class SuperArray {
private:
	T* ptr_{ nullptr };
	int size_{ 0 };
public:
	SuperArray() = default;

	SuperArray(const SuperArray<T>& source) {
		if (!source.isEmpty()) {
			size_ = source.size;
			ptr_ = new T[size_]{};

			for (int i = 0; i < size_; i++) {
				ptr_[i] = source.ptr_[i];
			}
		}
	}

	explicit SuperArray(int size) {
		if (size != 0) {
			ptr_ = new int[size] {};
			size_ = size;
		}
	}

	~SuperArray() {
		delete[] ptr_;
	}

	int size() const {
		return size_;
	}

	bool is_empty() const {
		return (size_ == 0);
	}

	bool is_valid_index(int index) const {
		return (index >= 0) && (index < size_);
	}

	int& operator[](int index) {
		if (!is_valid_index) {
			throw IndexOutOfBoundsException{ index + "is out of bounds" };
		}

		return ptr_[index];
	}

	int operator[](int index) const {
		if (!is_valid_index) {
			throw IndexOutOfBoundsException{ index + "is out of bounds" };
		}

		return ptr_[index];
	}

	friend std::ostream& operator<<(std::ostream& os, const SuperArray<T>& a) {
		
		for (int i = 0; i < a.size_; i++) {
			os << a[i];

			if (i != a.size_) {
				os << ", ";
			}
		}

		return os;
	}
};

#endif