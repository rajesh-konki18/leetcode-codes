#include <iostream>
using namespace std;

void printParanthesis(int n, int l, int r, int index, vector<char> str, vector<string> &res)
{
    if (index == 2 * n)
    {
        string temp = "";
        for (int i = 0; i < str.size(); i++)
        {
            temp.push_back(str[i]);
        }
        res.push_back(temp);
        return;
    }
    if (l == r)
    {
        str.push_back('(');
        printParanthesis(n, l + 1, r, index + 1, str, res);
    }
    else if (l > r)
    {
        if (l == n)
        {
            str.push_back(')');
            printParanthesis(n, l, r + 1, index + 1, str, res);
        }
        else
        {
            str.push_back('(');
            printParanthesis(n, l + 1, r, index + 1, str, res);
            str.pop_back();
            str.push_back(')');
            printParanthesis(n, l, r + 1, index + 1, str, res);
        }
    }
}
vector<string> generateParenthesis(int n)
{
    vector<string> res;
    vector<char> temp;
    printParanthesis(n, 0, 0, 0, temp, res);
    return res;
}