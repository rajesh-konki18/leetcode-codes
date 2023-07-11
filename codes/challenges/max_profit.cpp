#include <iostream>
#include <vector>

using namespace std;

long long int maxProfit(vector<long long int> &nums)
{
    long long int maxElement = 0;
    long long int size = nums.size();
    vector<long long int> preMin;
    vector<long long int> sufMax;
    preMin.push_back(nums[0]);
    for (long long int i = 1; i < size; i++)
    {
        preMin.push_back(min(nums[i], preMin[i - 1]));
    }
    sufMax.push_back(nums[size - 1]);
    for (long long int i = size - 2; i >= 0; i--)
    {
        sufMax.push_back(max(nums[i], sufMax[size - i - 2]));
    }

    for (long long int i = 0; i < size - 1; i++)
    {
        if (preMin[i] < sufMax[size - i - 2])
        {
            maxElement = max(maxElement, sufMax[size - i - 2] - preMin[i]);
        }
    }

    return maxElement;
}
int main()
{
    long long int n;
    cin >> n;

    vector<long long int> nums;
    for (long long int i = 0; i < n; i++)
    {
        long long int inp;
        cin >> inp;
        nums.push_back(inp);
    }

    cout << maxProfit(nums);
    return 0;
}