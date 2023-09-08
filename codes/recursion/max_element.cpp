#include <vector>
#include <climits>
#include <iostream>
using namespace std;

int getMax(vector<int> data, int i, int j)
{
    if (i == j)
    {
        return data[i];
    }

    if (j == i + 1)
    {
        return (data[i] > data[j]) ? data[i] : data[j];
    }
    int mid = (i + j) / 2;
    int x = getMax(data, i, mid);
    int y = getMax(data, mid + 1, j);
    return max(x, y);
}

int main()
{
    vector<int> a{7, 1, 4, 3, 2, 6, 5};
    int m = getMax(a, 0, a.size() - 1);
    cout << m;
    return 0;
}