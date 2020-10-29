#pragma once
#ifndef EASY_H
#define EASY_H

#include <vector>

class Easy {
	public:
		Easy() = default;

		std::vector<int> twoSum(std::vector<int>& numbers, int target);
};

#endif // !EASY_H

