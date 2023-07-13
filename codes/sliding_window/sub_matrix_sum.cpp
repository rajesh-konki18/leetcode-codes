#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

long long int getSum(vector<vector<long long int> > &nums, long long int n, long long int m){
    long long int ans = 0;
    long long mod = pow(10,9)+7;
    for (long long int i = 0; i < n; i++)
    {
        for (long long int j = 0; j < m; j++)
        {
           long long contribute = (((((i+1)%mod*(j+1)%mod)%mod*(n-i)%mod)%mod*(m-j)%mod)%mod*nums[i][j]%mod)%mod;
           ans = (ans%mod + contribute%mod)%mod;
        }
        
    }
    
    return ans;
}
int main(){
    vector<vector<long long int> > nums;
    long long int m,n;
    cin>>n>>m;
    for (long long int i = 0; i < n; i++)
    {
        vector<long long int> temp;
        for (long long int j = 0; j < m; j++)
        {
            long long  inp;
            cin>>inp;
            temp.push_back(inp);
        }
        nums.push_back(temp);
        
    }
    cout<<getSum(nums, n, m);
    

}