#include <iostream>

using namespace std;

bool isPallindrom(int number)
{
    if (number < 0)
    {
        return false;
    }

    int num = number;
    long int rev = 0;
    while (num != 0)
    {
        rev = rev * 10 + (num % 10);
        num = num / 10;
    }
    if (rev == number)
        return true;
    return false;
}

int main()
{
    cout << isPallindrom(1234567899) << endl;
    return 0;
}
