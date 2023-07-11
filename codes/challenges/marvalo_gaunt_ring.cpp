#include <iostream>
#include <vector>

using namespace std;

long long int maxSubSum(vector<long long int> &nums, int p, int q, int r)
{
    long long int maxElement = LLONG_MIN;
    int size = nums.size();
    vector<long long int> preMax;
    vector<long long int> sufMax;
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

    for (int i = 0; i < size; i++)
    {
        long long int temp = (nums[i] * q) + preMax[i] + sufMax[size - i - 1];
        maxElement = max(maxElement, temp);
    }

    return maxElement;
}
int main()
{
    int n, p, q, r;
    cin >> n >> p >> q >> r;

    vector<long long int> nums;
    for (int i = 0; i < n; i++)
    {
        long long int inp;
        cin >> inp;
        nums.push_back(inp);
    }

    cout << maxSubSum(nums, p, q, r);
    return 0;
}