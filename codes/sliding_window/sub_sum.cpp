#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

long long int getSubSum(vector<long long int> &nums){
    long long int size = nums.size();
    long long int ans = 0;
    long long modulo = pow(10,9)+7;
    for (long long int i = 0; i < size; i++)
    {
        long long int cont = ((nums[i] % modulo * (i+1) % modulo)%modulo * (size-i) % modulo) % modulo;
        ans= (ans%modulo+ cont)%modulo;
    }
    return ans;
    
}

int main(){
    vector<long long int> nums;
    long long int n;
    cin>>n;
    for (long long int i = 0; i < n; i++)
    {
        long long int inp;
        cin>>inp;
        nums.push_back(inp);
    }
    
    
    cout<<getSubSum(nums);
}