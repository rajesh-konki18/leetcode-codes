#include <iostream>

using namespace std;

string longestPalindrome(string s)
{
    int start = 0, maxLen = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int left = i;
        int right = i;
        int resLen = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--;
            right++;
        }
        resLen = right - left - 1;
        if (maxLen < resLen)
        {
            maxLen = resLen;
            start = left + 1;
        }
        left = i;
        right = i + 1;
        resLen = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--;
            right++;
        }
        resLen = right - left - 1;
        if (maxLen < resLen)
        {
            maxLen = resLen;
            start = left + 1;
        }
    }
    return s.substr(start, maxLen);
}

int main()
{
    cout << longestPalindrome("cbbd") << endl;
    return 0;
}
