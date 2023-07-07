#include <iostream>

using namespace std;

bool isMatch(string s, string p)
{
    bool matched = true;
    int regLen = p.length();
    for (int i = 0; i < regLen; i++)
    {
        if (p[i] == '.')
        {
            if (i < s.length())
                continue;
            else
                matched = false;
        }
        else if (p[i] != s[i])
        {
            matched = false;
        }
    }
    return matched;
}

int main()
{
    cout << isMatch("aa", "a.") << endl;
    return 0;
}