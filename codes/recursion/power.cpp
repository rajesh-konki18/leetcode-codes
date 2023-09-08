#include <iostream>
using namespace std;

double myPow(double x, int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
    {
        double negRes = myPow(1 / x, n / 2);
        if (n % 2 == 0)
            return 1 / negRes * 1 / negRes;
        return 1 / negRes * 1 / negRes * 1 / x;
    }
    else
    {
        double res = myPow(x, n / 2);
        if (n % 2 == 0)
            return res * res;
        return res * res * x;
    }
}
int main()
{
    int n = 2, k = -2;
    cout << myPow(n, k);
    return 1;
}