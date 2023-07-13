#include <iostream>
#include <vector>

using namespace std;

void rotate2d(vector<vector<int> > &nums){
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = size-1; j >= 0; j--)
        {
            cout<<nums[j][i];
        }
        cout<<endl;
    }


}

int main()
{
    vector<vector<int> > nums;
    int size;
    cin>>size;
    
    for (int i = 0; i < size; i++)
    {
        vector<int> temp;
        for (int j = 0; j < size; j++)
        {
            int inp;
            cin>>inp;
            temp.push_back(inp);
        }
        nums.push_back(temp);
    }
    rotate2d(nums);
    
    return 0;
}