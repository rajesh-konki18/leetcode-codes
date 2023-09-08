#include <iostream>
#include <vector>
#include<math.h>
#include<climits>
#include <bits/stdc++.h>

using namespace std;

void getMajorElement(vector<int> &nums)
{
    int first = INT_MAX,second = INT_MAX, count1 = 0,count2=0, size = nums.size();
    
    for (int i = 0; i < size; i++)
    {
        if (first == nums[i])
        {
            count1++;
        }
        
        else if(second == nums[i])
        {
            count2++;
        }
        else if (count1 == 0)
        {
            first = nums[i];
            count1++;
        }
        else if (count2 == 0)
        {
            second = nums[i];
            count2++;
        }else{
            count1--;
            count2--;
        }
        /* code */
    }
    if(size==1){
        first=nums[0];
    }
    count1=0;
    count2=0;
    for (int i = 0; i < size; i++)
    {
        if(nums[i]==first)count1++;
        else if(nums[i]==second)count2++;
    }
	bool flag = true;
	vector<int> ans;
    if(count1>floor(size/3)){
        ans.push_back(first);
		flag=false;
    }
    if(count2>floor(size/3)){
        ans.push_back(second);
		flag=false;
    }
   if(flag){
        ans.push_back(-1);
    }
	sort(ans.begin(),ans.end());
	for(auto x:ans)cout<<x<<" ";
	cout<<endl;
}

int main()
{
    int q;
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        vector<int> nums;
    int n;
    cin>>n;
    for (int j = 0; j < n; j++)
    {
        int inp;
        cin >> inp;
        nums.push_back(inp);
    }
     getMajorElement(nums);
        /* code */
    }
    
    
}