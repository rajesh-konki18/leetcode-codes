#include<iostream>
#include<vector>
#include<climits>
using namespace std;
long long getLongestSet(vector<long long int> &nums, long long int n){
   long long int llength = 0, maxLen = LLONG_MIN;
    for (long long int i = 0; i < n; i++)
    {
      llength=1;
      long long int val = nums[i];
      while (val!=i && val>=0)
      {
		  long long int temp = nums[val];
		  nums[val] = -(nums[val]+1);
          val = temp;
          llength++;
      }
      maxLen = max(maxLen, llength);
      
    }
    return maxLen;

    
    
}
int main(){
    // long long int n;
    // cin>>n;
    vector<long long int> nums;
    // for (long long int i = 0; i < n; i++)
    // {
    //     long long int inp;
    //     cin>>inp;
    //     nums.push_back(inp);
    //     /* code */
    // }
    nums.push_back(4);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(0);
    nums.push_back(2);
    
    cout<<getLongestSet(nums,6);

}