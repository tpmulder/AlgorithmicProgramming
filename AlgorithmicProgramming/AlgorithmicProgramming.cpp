#include <iostream>
#include "Easy.h"
#include "SuperArray.h"

using namespace std;

int main()
{
    Easy easy = Easy{};

    // input
    vector<int> inputTwoSum1 = vector<int> { 2, 7, 11, 15 };
    int inputTwoSum2 = 9;

    cout << easy.TwoSum(inputTwoSum1, inputTwoSum2)[0] << endl;
}

string join(const vector<string> arr, const string sep) {

    string str;

    for (int i = 0; i < arr.size(); i++)
    {

    }

    for (const auto& piece : arr)
    {
        str += piece;
    }

    return str;
}
