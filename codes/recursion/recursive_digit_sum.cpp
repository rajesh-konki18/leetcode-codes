#include <iostream>
#include <string>
using namespace std;

string appendStrings(string n, int k)
{
    string temp = n;
    if (k <= 1)
        return n;
    for (int i = 0; i < k; i++)
    {
        n.append(temp);
    }
    return n;
}

int recursiveDigitSum(string n, int p)
{
    n = appendStrings(n, p);
    if (n.length() == 1)
    {
        return n[0] - '0';
    }
    int sum = 0;
    for (int i = 0; i < n.size(); i++)
    {
        sum += (int(n[i]) - 48);
    }
    return recursiveDigitSum(to_string(sum * p), 1);
}

int main()
{
    cout << recursiveDigitSum("2", 2);
    return 0;
}