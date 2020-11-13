#pragma once
#ifndef EASY_H
#define EASY_H

#include <vector>

class Easy {
public:
	static std::vector<int> two_sum(std::vector<int>& numbers, int target);
	static int reverse(int x);
	static bool is_palindrome(int x);
	static int binary_search(std::vector<int>& nums, int target);

private:
	Easy() = default;
};

#endif // !EASY_H