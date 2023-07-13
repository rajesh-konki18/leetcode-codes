#include <iostream>
#include <vector>

using namespace std;

void findFrequency(vector<int> &nums, int k, int x)
{
    int count = 0;
    for (int i = 0; i < k; i++)
    {
        if (nums[i] == x)
            count++;
    }
    cout << count;
    int size = nums.size();
    for (int i = k; i < size; i++)
    {
        if (nums[i] == x)
            count++;
        if (nums[i - k] == x)
            count--;
        cout << count;
    }
}

int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(6);
    nums.push_back(2);
    findFrequency(nums, 4, 2);
    return 0;
}