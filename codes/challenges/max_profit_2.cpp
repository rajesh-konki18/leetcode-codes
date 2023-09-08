#include <iostream>
#include <vector>
#include <climits>

using namespace std;

long long int maxProfit(vector<long long int> &nums, long long int size)
{
    long long int maxElement = 0;

    long long int sectran[size];
    if (size == 1)
        return 0;
    if (size == 2)
    {
        if (nums[1] > nums[0])
            return nums[1] - nums[0];
        else
        {
            return 0;
        }
    }
    sectran[size - 1] = 0;
    long long int maxNum = nums[size - 1];
    for (long long int i = size - 2; i >= 0; i--)
    {
        sectran[i] = max(sectran[i + 1], maxNum - nums[i]);
        maxNum = max(maxNum, nums[i]);
    }

    long long int firsttran[size];
    firsttran[0] = 0;
    long long int minNum = nums[0];
    long long int maxProfit = LLONG_MIN;
    for (long long int i = 1; i < size - 1; i++)
    {
        firsttran[i] = max(firsttran[i - 1], nums[i] - minNum);
        maxProfit = max(maxProfit, firsttran[i] + sectran[i]);
        minNum = min(minNum, nums[i]);
    }

    return maxProfit;
}
int main()
{
    long long int n;
    cin >> n;

    vector<long long int> nums;

    for (long long i = 0; i < n; i++)
    {
        long long int inp;
        cin >> inp;
        nums.push_back(inp);
    }

    cout << maxProfit(nums, n);
    return 0;
}