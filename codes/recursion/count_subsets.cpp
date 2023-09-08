#include <iostream>
using namespace std;

vector<int> nums{1, 2, 3, 0};
int countNum = 0;

void countSubsetsSum(int startIndex, int sum)
{
    if (startIndex == nums.size())
    {
        if (sum == 0)
            countNum++;
        return;
    }
    countSubsetsSum(startIndex + 1, sum - nums[startIndex]);
    countSubsetsSum(startIndex + 1, sum);
}

int main()
{
    countSubsetsSum(0, 3);
    cout << countNum;
    return 0;
}