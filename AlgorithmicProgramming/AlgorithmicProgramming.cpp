#include "Easy.h"
#include "SuperArray.h"
#include "SuperStack.h"

using namespace std;

int main()
{
    Easy easy = Easy{};

    // input
    auto inputTwoSum1 = vector<int> { 2, 7, 11, 15 };
    int inputTwoSum2 = 9;
    cout << easy.twoSum(inputTwoSum1, inputTwoSum2)[0] << endl;
}
