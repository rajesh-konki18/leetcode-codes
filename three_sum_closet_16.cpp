#include <iostream>
#include <vector>

using namespace std;


int threeSumClosest(vector<int>& nums, int target)
{
     long int min = MAX_INPUT;
    sort(nums.begin(), nums.end());
    int size = nums.size();
    int res ;
    for (int i = 0; i < size - 1; i++)
    {
        int left = i+1;
        int right = size - 1;
        while (left< right)
        {
           int sum = nums[i] + nums[left] + nums[right];
           if(sum == target){
            return sum;
           }
           if(abs(sum - target) < abs(min - target)){
            min = sum;
           }
           if(sum < target){
            left++;
           }
           else{
            right--;
           }
        }
    }
    return min;
    
  
}
int main()
{
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(0);
    nums.push_back(5);
    nums.push_back(-5);
     nums.push_back(3);
    nums.push_back(3);
    nums.push_back(0);
    nums.push_back(-4);
    nums.push_back(-5);

    cout<<threeSumClosest(nums, -2);
    return 0;
}
