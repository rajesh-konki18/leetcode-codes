#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;


vector<vector<int> > threeSum(vector<int> &nums)
{
    int size = nums.size();
    vector<vector<int> > res;
    if (size < 3)
    {
        return res;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < size - 1; i++)
    {
        int left = i + 1;
        int right = size - 1;
        while (left < right)
        {
            int val = nums[left] + nums[right] + nums[i];
            if (val == 0)
            {
                vector<int> temp;
                temp.push_back(nums[left]);
                temp.push_back(nums[i]);
                temp.push_back(nums[right]);
                sort(temp.begin(),temp.end());
                res.push_back(temp);
                while (left < right and nums[left] == nums[left + 1])
                    left += 1;
                while (left < right and nums[right] == nums[right - 1])
                    right -= 1;
                left++;
                right--;
            }
            else if (val < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    return res;
}
int main()
{
    vector<int> nums;
    nums.push_back(-4);
    nums.push_back(-2);
    nums.push_back(-2);
    nums.push_back(-2);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(4);
    nums.push_back(6);
    nums.push_back(6);

    vector<vector<int> > result = threeSum(nums);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
