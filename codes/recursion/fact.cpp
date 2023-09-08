#include <iostream>
using namespace std;

int fact(int n)
{
    if (n == 0)
        return 1;
    return fact(n - 1) * n;
}
int main()
{
    int y = fact(5);
    cout << y;
    return 1;
}