#include <iostream>
using namespace std;

vector<int> nums{
    1,
    2,
};
int countNum = 0;

void countSubsetsSum(int startIndex, int sum)
{

    if (sum <= 0 || startIndex == 2)
    {
        if (sum == 0)
            countNum++;
        return;
    }
    countSubsetsSum(startIndex, sum - nums[startIndex]);
    countSubsetsSum(startIndex + 1, sum);
}

int main()
{
    countSubsetsSum(0, 4);
    cout << countNum;
    return 0;
}