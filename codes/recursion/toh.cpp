#include <iostream>
#include <vector>
using namespace std;

void getMovement(int N, int source, int helper, int destination, int &n, int &counter, vector<int> &res)
{
    // vector<int> res;
    if (N > 0)
    {

        getMovement(N - 1, source, destination, helper, n, counter, res);
        counter++;
        if (counter == n)
        {
            res.push_back(source);
            res.push_back(destination);
            return;
        }
        getMovement(N - 1, helper, destination, source, n, counter, res);
    }
}
vector<int> shiftPile(int N, int n)
{
    // code here
    vector<int> res;
    int counter = 0;
    getMovement(N, 1, 2, 3, n, counter, res);
    return res;
}
int main()
{
    vector<int> res = shiftPile(4, 5);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
    }
}
