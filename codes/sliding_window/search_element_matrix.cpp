#include<iostream>
#include<vector>
using namespace std;
bool searchMatrix(vector<vector<int> >& matrix, int target) {
    bool available = false;
    
    int m = matrix.size();
    if(m==0)return available;
    int n = matrix[0].size();
    for (int i = 0; i < m;)
    {
        for (int j = n-1; j < n;)
        {
           if(matrix[i][j]== target){
            return true;
           }
           else if(matrix[i][j]<target){
            
            i++;
            break;
           }
           else{
            j--;
           }
        }
        
    }
    
    return available;
        
    }
 int main(){
    vector<vector<int> > nums{
        {1,4,7,11,15},
        {2,5,8,16,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };
    cout<<searchMatrix(nums,5);


 }   