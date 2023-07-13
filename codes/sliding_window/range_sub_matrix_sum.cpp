#include<iostream>
#include<vector>


using namespace std;

void getSum(vector<vector<long long int> > &nums, long long int m, long long int n, long long int q){
    //row preSum
    
    for (long long int i = 0; i < m; i++)
    {
        long long int sum = nums[i][0];
        for (long long int j = 1; j < n; j++)
        {
            nums[i][j]+=nums[i][j-1];
        }
        
    }
    for (long long int i = 0; i < m; i++)
    {
        long long int sum = nums[0][i];
        for (long long int j = 1; j < n; j++)
        {
            nums[j][i]+=nums[j-1][i];
        }
        
    }
    for (long long int i = 0; i < q; i++)
    {
        long long int i1,i2,j1,j2;
        cin>>i1;
        cin>>j1;
        cin>>i2;
        cin>>j2;
        long long int ans = nums[i2][j2];
    if(j1>0 && i1>0)
    {
        ans-=nums[i2][j1-1];
        ans-=nums[i1-1][j2];
        ans+=nums[i1-1][j1-1];
    }
    else if(j1>0)
    {
        ans-=nums[i2][j1-1];
    }
    else if(i1>0)
    {
        ans-=nums[i1-1][j2];
    }
    else{
        ans = nums[i2][j2];
    }
   cout<<ans<<endl;
    }
    
    
    
    
}

int main(){
    long long int m , n, q;
    cin>>m>>n;
    vector<vector<long long int> > nums;
    for (long long int i = 0; i < m; i++)
    {
        vector<long long int> temp;
        for (long long int j = 0; j < n; j++)
        {
            long long int inp;
            cin>>inp;
            temp.push_back(inp);
        }
        nums.push_back(temp);
        
    }
    cin>>q;
    getSum(nums,m,n,q);
    return 0;
}