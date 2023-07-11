#include <iostream>
#include <vector>
#include <climits>
using namespace std;

long long int chunksCount(vector<long long int> &nums)
{
    long long int count = 0;
    long long int maxEle = LLONG_MIN;
    long long int size = nums.size();
    if (size == 0 || size == 1)
        return 1;

    for (long long int i = 0; i < size; i++)
    {
        maxEle = max(maxEle, nums[i]);
        if (maxEle == i)
            count++;
    }

    return count;
}
int main()
{
    long long int n;
    cin >> n;
    vector<long long int> nums;
    // for (long long i = 0; i < n; i++)
    // {
    //     long long inp;
    //     cin >> inp;
    //     nums.push_back(inp);
    // }
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);

    cout << chunksCount(nums);
    return 0;
}