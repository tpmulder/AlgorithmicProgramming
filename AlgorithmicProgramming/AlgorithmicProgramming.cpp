#include "Easy.h"
#include "SuperArray.h"
#include "SuperStack.h"
#include "Excercise.h"
#include<tuple>

using namespace std;

// vector overload for easy printing
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1)
            os << ", ";
    }
    os << "]\n";
    return os;
}

int main()
{
    // TwoSum
    vector<int> inputTwoSum1 = vector<int> { 2, 7, 11, 15 };
    int inputTwoSum2 = 9;

    string nameTwoSum = "TwoSum";
    string inputTwoSum = "numbers: { 2, 7, 11, 15 }, target: 9";

    function<vector<int>()> fn = [inputTwoSum1, inputTwoSum2]()-> vector<int>{
        vector<int> inp = inputTwoSum1;
        return Easy::two_sum(inp, inputTwoSum2);
    };

    auto exc1 = new Excercise<vector<int>>(nameTwoSum, inputTwoSum, fn);

    cout << exc1->to_string();
}
