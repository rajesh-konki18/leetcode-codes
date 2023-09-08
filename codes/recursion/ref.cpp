#include <iostream>
using namespace std;

void func(int &n)
{
    cout << n << endl;
    if (n >= 3)
        return;
    n++;
    func(n);
    n++;
    func(n);
}
int main()
{
    int x = 0;
    func(x);
    return 1;
}