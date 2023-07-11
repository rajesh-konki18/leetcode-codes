#include <iostream>
#include <vector>

using namespace std;

long long int getHeight(vector<long long int> &nums)
{
    long long int sum = 0;
    long long int size = nums.size();
    vector<long long int> preMax;
    vector<long long int> sufMax;
    preMax.push_back(nums[0]);
    for (int i = 1; i < size; i++)
    {
        preMax.push_back(max(nums[i], preMax[i - 1]));
    }
    sufMax.push_back(nums[size - 1]);
    for (int i = size - 2; i >= 0; i--)
    {
        sufMax.push_back(max(nums[i], sufMax[size - i - 2]));
    }
    nums[0] = 0;
    for (int i = 1; i < size - 1; i++)
    {
        if ((preMax[i - 1] > nums[i]) && (sufMax[size - i - 2] > nums[i]))
        {
            nums[i] = min(preMax[i - 1], sufMax[size - i - 2]) - nums[i];
            sum += nums[i];
        }
        else
        {
            nums[i] = 0;
        }
    }

    return sum;
}
int main()
{
    long int n;
    cin >> n;

    vector<long long int> nums;
    for (long long i = 0; i < n; i++)
    {
        long long int inp;
        cin >> inp;
        nums.push_back(inp);
    }
    cout << getHeight(nums);
    return 0;
}