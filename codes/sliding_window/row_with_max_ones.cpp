#include<iostream>
#include<vector>

using namespace std;

int getRowWithMaxOnes(vector<vector<int> > &mat, int n, int m){
    int index;
    int i=m-1;
    int j=0;
    int counter = 0;
    while(i>=0 && j<n){
        if(mat[j][i]==1){
            index = j;
            i--;
            counter++;
        }
        else{
           j++;     
        }
    }
    if(counter == 0) return -1;
    return index;

}

int main(){
    vector<vector<int> > nums;
    for (int i = 0; i < 4; i++)
    {
        vector<int> temp;
       if(i==0){
        temp.push_back(0);
        temp.push_back(1);
        temp.push_back(1);
        temp.push_back(1);
       }
       else if(i==1){
        temp.push_back(0);
        temp.push_back(0);
        temp.push_back(1);
        temp.push_back(1);
       }
       else if(i==2){
        temp.push_back(1);
        temp.push_back(1);
        temp.push_back(1);
        temp.push_back(1);
       }
       else if(i==3){
        temp.push_back(0);
        temp.push_back(0);
        temp.push_back(0);
        temp.push_back(0);
       }
       nums.push_back(temp);
    }
    
     
    cout<<getRowWithMaxOnes(nums,4,4);

    return 0;
}