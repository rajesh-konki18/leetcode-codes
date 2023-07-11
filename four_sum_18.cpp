#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;


vector<vector<int> > fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = i+1; j < size - 2; j++)
            {
                int left = j+1;
                int right = size - 2;
                while(left < right){
                    int val = nums[i] + nums[j] + nums[left] + nums[right];
                    if(val == target){
                        
                vector<int> temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                temp.push_back(nums[left]);
                temp.push_back(nums[right]);
                sort(temp.begin(),temp.end());
                res.push_back(temp);
                // while (left < right && nums[left] == nums[left + 1])
                //     left += 1;
                // while (left < right && nums[right] == nums[right - 1])
                //     right -= 1;
                left++;
                right--;
            }
            else if(val < target){
                left++;
            }
            else{
                right--;
            }

                    }
                }
               
            }
            return res;
            
        }
        
    
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(-2);
    nums.push_back(2);
    //[1,0,-1,0,-2,2]

    vector<vector<int> > result = fourSum(nums,0);
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
