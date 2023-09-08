#include <iostream>
using namespace std;

void transformData(int a, int &b, vector<int> &res, vector<int> temp)
{
    if (a < b)
    {
        temp.push_back(a);
    }
    if (a >= b)
    {
        if (a == b)
        {
            for (int i = 0; i < temp.size(); i++)
            {
                res.push_back(temp[i]);
            }
            res.push_back(a);
        }
        return;
    }
    transformData(a * 2, b, res, temp);
    transformData(a * 10 + 1, b, res, temp);
}

int main()
{
    vector<int> res, temp;
    int a, b;
    cin >> a >> b;
    transformData(a, b, res, temp);
    if (res.size() > 0)
    {
        cout << "YES" << endl
             << res.size() << endl;
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i] << " ";
        }
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}