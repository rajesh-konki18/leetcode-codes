#include <iostream>

using namespace std;

string convert(string s, int numRows)
{
    if (numRows == 1)
        return s;
    int maxGap = 2 * numRows - 2;
    int first = maxGap;
    int second = 0;
    string res = "";
    for (int i = 0; i < numRows; i++)
    {
        int temp = 0;
        for (int j = i; j < s.length();)
        {

            res += s[j];
            if (first == 0 || second == 0)
            {
                j += (first == 0) ? second : first;
            }
            else
            {
                if (temp % 2 == 0 && first > 0)
                {
                    j += first;
                }
                // PINALSIGYAHRPI
                else if (temp % 2 == 1 && second > 0)
                {
                    j += second;
                }
            }

            temp++;
        }
        first = first - 2;
        second = second + 2;
    }
    return res;
}

int main()
{
    cout << convert("PAYPALISHIRING", 4) << endl;
    return 0;
}