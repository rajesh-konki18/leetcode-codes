#include <iostream>
#include <vector>
using namespace std;

void rearrange(vector<long long int> &nums)
{
    int n = nums.size();
    for (long long int i = 0; i < n; i++)
    {
        if (nums[i] >= 0)
        {
            long long int index = nums[i];
            long long int val = i;
            while (i != index)
            {
                long long int temp = nums[index];
                nums[index] = -(val + 1);
                val = index;
                index = temp;
            }
            nums[index] = -(val + 1);
        }
    }
    for (long long int i = 0; i < n; i++)
    {
        cout << -(1 + nums[i]);
    }
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
        /* code */
    }
    rearrange(nums);
    return 0;
}