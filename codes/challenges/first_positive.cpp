#include<iostream>
#include<vector>
using namespace std;

long long int getFirstPositive(vector<long long int> &nums, long long int n){
    for (long long int i = 0; i < n; i++)
    {
        long long int val = nums[i];
        long long int pos = val - 1;
        if(val>=1 && val<=n){
            if(nums[pos]!=val){
                long long int temp = nums[pos];
                nums[pos] = nums[i];
                nums[i] = temp;
                i--;
            }

        }
        
    }
    for (long long int i = 0; i < n; i++)
    {
        if(nums[i]!=i+1)return i+1;
    }
    return n+1;
    
    
}

int main(){
    
    long long int q;
    cin>>q;
    for (long long int i = 0; i < q; i++)
    {
        long long int n;
        cin>>n;
        vector<long long int> nums;
        for (long long  j = 0; j < n; j++)
        {
            long long inp;
            cin>>inp;
            nums.push_back(inp);
        }
        cout<<getFirstPositive(nums,n)<<endl;
        
    }
    

}