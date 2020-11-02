#include "Easy.h"
#include <unordered_map>
#include <string> 
#include <cmath>

using namespace std;

vector<int> Easy::twoSum(vector<int>& nums, int target) {

	vector<int> arr;
	int diff;
	unordered_map<int, int> m;

	for (int i = 0; i < nums.size(); i++) {
		diff = target - nums[i];
		if (m.find(diff) != m.end() && m.find(diff)->second != i) {
			arr.push_back(i);
			arr.push_back(m.find(diff)->second);
			return arr;
		}
		m[nums[i]] = i;
	}
	return arr;
};

int Easy::reverse(int x) {

    if (x < (-1) * (pow(2, 31) - 1) || x > (pow(2, 31) - 1)) return 0;
    int n = 0, i = 10, e, p = x, j = 0;
    long long output = 0;
    vector<int> res;

    if (x < 0) x = x * (-1);
    while (x > 0) {
        n = x % 10;
        res.push_back(n);
        x = x / 10;
    }
    e = res.size();

    while (j < e) {
        if (output > (pow(2, 31) - 1)) return 0;
        output += (res[j] * (pow(10, e - 1 - j)));
        j++;
    }
    if (output > (pow(2, 31) - 1)) return 0;
    if (p < 0) return output * (-1);
    else return output;
};

bool Easy::isPalindrome(int x) {

    if (x < 0) return false;
    string s = to_string(x), t = s;
    int n = s.size();
    for (int i = 0, j = n - 1; i < j; i++, j--)
        t[i] ^= t[j] ^= t[i] ^= t[j];
    return (t == s);
};

int Easy::binarySearch(vector<int>& nums, int target) {

    int m, b = 0, e = nums.size() - 1;
    while (b <= e) {
        m = b + (e - b) / 2;
        if (nums[m] == target) return m;
        if (target < nums[m]) e = m - 1;
        else b = m + 1;
    }
    return -1;
};