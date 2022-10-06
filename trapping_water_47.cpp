#include<iostream>
#include<vector>
using namespace std;


int trap(vector<int>& arr){
    vector<int> minArr, maxArr;
    int min = 0, max = 0;

    for(auto i = arr.begin(); i != arr.end(); i++){
       minArr.push_back(min);
       if(*i > min){
        min = *i;
       }
    }
    for(auto i = arr.begin(); i != arr.end(); i++){
       cout<<*i;
    }
    return 0;

}

int main(){
    vector<int> arr;
    arr.push_back(4);
    arr.push_back(2);
    arr.push_back(0);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(5);
    cout<<trap(arr);
    return 0;
}
