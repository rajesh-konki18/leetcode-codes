#include <iostream>
#include <vector>

using namespace std;

int maxSubSum(vector<int> &nums, int p, int q, int r)
{
    int maxElement = INT_MIN;
    int size = nums.size();
    vector<int> preMax;
    vector<int> sufMax;
    preMax.push_back(nums[0] * p);
    for (int i = 1; i < size; i++)
    {
        preMax.push_back(max(nums[i] * p, preMax[i - 1]));
    }
    sufMax.push_back(nums[size - 1] * r);
    for (int i = size - 2; i >= 0; i--)
    {
        sufMax.push_back(max(nums[i] * r, sufMax[size - i - 2]));
    }

    for (int i = 1; i < size - 1; i++)
    {
        int temp = (nums[i] * q) + preMax[i - 1] + sufMax[size - i - 2];
        maxElement = max(maxElement, temp);
    }

    return maxElement;
}
int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(-2);
    nums.push_back(5);
    nums.push_back(4);
    nums.push_back(6);
    nums.push_back(9);
    nums.push_back(-1);

    cout << maxSubSum(nums, 2, 3, -2);
    return 0;
}