#pragma once
#ifndef SUPERSTACK_H
#define SUPERSTACK_H

#include <ostream>
#include "SuperArray.h"

class StackOverflowException : public std::exception { };

template <typename T>
class SuperStack {
private:
	SuperArray<T> array_;
	int top_;

public:
	explicit SuperStack(int maxStackSize)
		: array_{maxStackSize}
		, top_{-1}
	{}

	void push(const T& element) {
		if (size() >= max_size()) {
			throw StackOverflowException{ "Stack overflow!" };
		}

		top_++;
		array_[top_] = element;
	}

	const T& top() const {
		return array_[top_];
	}

	int size() const {
		return (top_ + 1);
	}

	bool is_empty() const {
		return size() == 0;
	}

	int max_size() const {
		return array_.size();
	}

	void clear() {
		top_ = -1;
	}

	friend std::ostream& operator<<(std::ostream& os, const SuperStack& stack) {
		if (stack.is_empty()) {
			os << "*** Empty Stack ***" << std::endl;
			return os;
		}

		for (int i = 0; i < stack.top_; i++)
		{
			os << stack.array_[i];

			if (i != stack.array_.size()) {
				os << ", ";
			}
		}

		return os;
	}
};

#endif // !SUPERSTACK_H
