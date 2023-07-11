#include <iostream>
#include <vector>

using namespace std;

long long int maxProfit(vector<long long int> &nums)
{
    long long int maxElement = 0;
    long long int size = nums.size();
    vector<long long int> profit;
    // profit.push_back(nums[0]);
    // for (long long int i = 1; i < size; i++)
    // {
    //     preMin.push_back(min(nums[i], preMin[i - 1]));
    // }
    long long int maxEle = nums[size - 1];
    profit.push_back(0);
    for (long long int i = size - 2; i >= 0; i--)
    {
        profit.push_back(max(profit[i + 1], maxEle - nums[i]));
        maxEle = max(maxEle, nums[i]);
    }
    vector<long long int> res;
    res.push_back(0);
    long long int minEle = nums[0];
    for (long long int i = 1; i < size; i++)
    {
        res.push_back(max(res[i - 1], nums[i] - minEle) + profit[i + 1]);
        minEle = min(minEle, nums[i]);
    }

    return maxElement;
}
int main()
{
    // long long int n;
    // cin >> n;

    vector<long long int> nums;
    // for (long long int i = 0; i < n; i++)
    // {
    //     long long int inp;
    //     cin >> inp;
    //     nums.push_back(inp);
    // }
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(4);

    cout << maxProfit(nums);
    return 0;
}