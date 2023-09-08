#include <iostream>
#include <vector>
#include<math.h>
using namespace std;

int getMajorElement(vector<int> &nums)
{
    int element = nums[0], count = 1, size = nums.size();
    for (int i = 1; i < size; i++)
    {
        if (element == nums[i])
        {
            count++;
        }
        
        else
        {
            count--;
        }
        if (count == 0)
        {
            element = nums[i];
            count++;
        }
        /* code */
    }
    return element;
}

int main()
{
    vector<int> nums;
    int n;
    // for (int i = 0; i < n; i++)
    // {
    //     int inp;
    //     cin >> inp;
    //     nums.push_back(inp);
    // }
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    cout<<floor(13/3);

    cout << getMajorElement(nums);
}