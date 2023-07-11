#include <iostream>
#include <vector>

using namespace std;

void reverse(vector<long long int> &nums, long long int start, long long int end)
{
    long long int temp;
    while (start < end)
    {
        temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotateK(vector<long long int> &nums, long long int k, long long int n)
{
    reverse(nums, 0, n - k - 1);
    reverse(nums, n - k, n - 1);
    reverse(nums, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
}
int main()
{
    long int n, k;
    cin >> n >> k;

    vector<long long int> nums;
    for (long long i = 0; i < n; i++)
    {
        long long int inp;
        cin >> inp;
        nums.push_back(inp);
    }

    rotateK(nums, k % n, n);
    return 0;
}