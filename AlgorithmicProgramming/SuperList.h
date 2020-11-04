#pragma once

#ifndef SUPERLIST_H
#define SUPERLIST_H

#include <cassert>
#include <ostream>

template <typename T>
class SuperList {
private:
	struct Node {
		Node* next{ nullptr };
		T data{};

		Node() = default;

		explicit Node(const T& d)
			: data{ d } {}

		Node(const T& d, Node* n)
			: data{ d }, next{ n } {}
	};

	Node* head_{ nullptr };
	int count_{ 0 };

	SuperList(const SuperList&) = delete;
	SuperList& operator=(const SuperList) = delete;

public:
	typedef Node* Position;

	SuperList() = default;

	~SuperList() {
		clear();
	}

	int count() const {
		return count_;
	}

	bool is_empty() const {
		return (count_ == 0);
	}

	void clear() {
		while (!is_empty()) {
			remove_head();
		}
	}

	void insert_head(const T& value) {
		Node* n = new Node{ value };

		node->next = head_;
		head_ = n;

		++count_;
	}

	void remove_head() {
		assert(!is_empty());

		Node* h = head_->next;

		delete head_;

		head_ = h;

		--count_;
	}

	T element_at(Position node) {
		assert(!is_empty());
		assert(node != nullptr);

		return node->data;
	}

	void insert_after(Position node, const T& value) {
		assert(node != nullptr);

		Node* n = new Node{ value };

		n->next = node->next;
		node->next = n;

		++count_;
	}

	void remove_after(const T& value) {
		assert(!is_empty);
		assert(node != nullptr);

		Node* n = node->next;
		node->next = n->next;

		delete n;

		--count_;
	}

	Position find(const T& value) {
		if (is_empty()) {
			return nullptr;
		}
		else {
			Node* node = head_;
			while (node != nullptr) {
				if (node->data == value) {
					return node;
				}

				node = node->next;
			}
		}
	};

	friend std::ostream& operator<<(std::ostream& os, const SuperList<T>& list) {
		if (list.is_empty()) {
			os << "***Empty List***";
			return os;
		}
		else {
			Node* node = list.head_;
			while (node != nullptr) {
				os << node->data << ", ";

				node = node->next;
			}
		}
	};
};

#endif // !SUPERLIST_H
