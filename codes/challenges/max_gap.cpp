#include <iostream>
#include <vector>
#include <climits>

using namespace std;
long long int findGap(vector<long long int> &nums)
{
    long long int n = nums.size();
    if (n < 2)
        return 0;
    long long int minInt = LLONG_MAX, maxInt = LLONG_MIN;
    long long int maxArr[n], minArr[n];
    for (long long int i = 0; i < n; i++)
    {
        sqrt
            minInt = min(minInt, nums[i]);
        maxInt = max(maxInt, nums[i]);
        minArr[i] = LLONG_MAX;
        maxArr[i] = LLONG_MIN;
    }
    if (minInt == maxInt)
        return 0;
    long long int gap = (maxInt - minInt) / (n - 1);
    if (((maxInt - minInt) % (n - 1)) != 0)
        gap++;

    for (long long int i = 0; i < n; i++)
    {
        long long int bucket = (nums[i] - minInt) / gap;
        minArr[bucket] = min(minArr[bucket], nums[i]);
        maxArr[bucket] = max(maxArr[bucket], nums[i]);
    }
    long long int ans = LLONG_MIN, prev = LLONG_MIN;
    for (long long int i = 0; i < n; i++)
    {
        if (minArr[i] == LLONG_MAX)
            continue;
        if (prev == LLONG_MIN)
        {
            prev = maxArr[i];
        }
        else
        {
            ans = max(ans, minArr[i] - prev);
            prev = maxArr[i];
        }
    }

    return ans;
}

int main()
{
    long long int q;
    cin >> q;

    for (long long i = 0; i < q; i++)
    {
        vector<long long int> nums;
        int n;
        cin >> n;
        for (long long i = 0; i < n; i++)
        {
            long long int inp;
            cin >> inp;
            nums.push_back(inp);
        }
        cout << findGap(nums) << endl;
    }
}