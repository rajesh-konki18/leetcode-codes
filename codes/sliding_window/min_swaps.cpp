#include <iostream>
#include <vector>
#include <climits>

using namespace std;

long long int findMinSwaps(vector<long long int> &nums, long long int pivot)
{
    long long int ws = 0;
    long long int minSwaps = LLONG_MIN;
    long long int size = nums.size();
    for (long long int i = 0; i < size; i++)
    {
        if (nums[i] <= pivot)
            ws++;
    }
    long long int counter = 0;
    for (long long int i = 0; i < ws; i++)
    {
        if (nums[i] > pivot)
            counter++;
    }
    minSwaps = counter;
    for (long long int i = ws; i < size; i++)
    {
        if (nums[i] > pivot)
            counter++;
        if (nums[i - ws] > pivot)
            counter--;
        minSwaps = min(minSwaps, counter);
    }
    return minSwaps;
}

int main()
{
    long long int n;
    cin >> n;
    long long int k;
    cin >> k;
    vector<long long int> nums;
    for (long long int i = 0; i < n; i++)
    {
        long long int inp;
        cin >> inp;
        nums.push_back(inp);
    }

    cout << findMinSwaps(nums, 3);
}