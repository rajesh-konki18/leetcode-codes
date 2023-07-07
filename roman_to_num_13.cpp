#include <iostream>

using namespace std;

int romanToInt(string s)
{
    int res = 0;
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        switch (s[i])
        {
        case 'M':
            res += 1000;
            break;
        case 'D':
            res += 500;
            break;
        case 'C':
            if (i + 1 < len && s[i + 1] == 'D')
            {
                res += 400;
                i++;
            }
            else if (i + 1 < len && s[i + 1] == 'M')
            {
                res += 900;
                i++;
            }
            else
                res += 100;
            break;
        case 'L':
            res += 50;
            break;

        case 'X':
            if (i + 1 < len && s[i + 1] == 'L')
            {
                res += 40;
                i++;
            }
            else if (i + 1 < len && s[i + 1] == 'C')
            {
                res += 90;
                i++;
            }
            else
                res += 10;
            break;
        case 'V':
            res += 5;
            break;
        case 'I':
            if (i + 1 < len && s[i + 1] == 'V')
            {
                res += 4;
                i++;
            }
            else if (i + 1 < len && s[i + 1] == 'X')
            {
                res += 9;
                i++;
            }
            else
                res += 1;
            break;

        default:
            res += 0;
            break;
        }
    }
    return res;
}

int main()
{
    cout << romanToInt("LVIII") << endl;
    return 0;
}
