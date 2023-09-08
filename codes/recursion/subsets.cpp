#include <iostream>
using namespace std;
int arr[3] = {1, 2, 3};
int noOfElements = 0;
void printSubsets(int x, vector<int> a)
{
    if (x == 3)
    {
        for (int i = 0; i < a.size(); i++)
        {
            cout << a[i];
        }
        noOfElements++;
        cout << endl;
        return;
    }
    printSubsets(x + 1, a);
    a.push_back(arr[x]);
    printSubsets(x + 1, a);
}

int main()
{
    vector<int> a;
    printSubsets(0, a);
    cout << "No Of Subsets" << noOfElements;

    return 0;
}