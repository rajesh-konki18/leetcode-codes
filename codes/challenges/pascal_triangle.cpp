#include <iostream>
#include<vector>

using namespace std;
int main()
{
    int n;
    cin>>n;
    int nums[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(j==0){
                nums[i][j]=1;
            }
            else{
                nums[i][j]=0;
            }
        }
        
    }
    
    
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <n; j++)
        {
            nums[i][j]=nums[i-1][j-1]+nums[i-1][j];
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <=i; j++)
        {
            cout<<nums[i][j]<<" ";
        }
        cout<<endl;
    }
}