#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int getMin(int f, int s)
{
    return f < s ? f : s;
}
int trap(vector<int> &arr)
{
    vector<int> minArr, maxArr;
    int min = 0, max = 0;

    for (auto i = arr.begin(); i != arr.end(); i++)
    {
        minArr.push_back(min);
        if (*i > min)
        {
            min = *i;
        }
    }
    int arr_size = arr.size();
    for (auto i = arr_size - 1; i >= 0; i--)
    {
        maxArr.push_back(max);
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    reverse(maxArr.begin(), maxArr.end());
    int sum = 0;
    for (int i = 0; i <= arr_size - 1; i++)
    {
        int t = (getMin(minArr[i], maxArr[i]) - arr[i]);
        if (t > 0)
        {
            sum += t;
        }
    }
    return sum;
}

int main()
{
    vector<int> arr;
    arr.push_back(4);
    arr.push_back(2);
    arr.push_back(0);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(5);
    cout << trap(arr);
    return 0;
}
