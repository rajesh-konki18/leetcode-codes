#include <iostream>
using namespace std;

void printParanthesis(int n, int m, int l, int r, int s, int t, int index, vector<char> str, vector<string> &res)
{
    if (index == 2 * (n + m))
    {
        string temp = "";
        for (int i = 0; i < str.size(); i++)
        {
            temp.push_back(str[i]);
        }
        res.push_back(temp);
        return;
    }
    if (l == r && s == t)
    {
        if (l != n)
        {
            str.push_back('(');
            printParanthesis(n, m, l + 1, r, s, t, index + 1, str, res);
        }
        if (s != m)
        {
            str.push_back('{');
            printParanthesis(n, m, l, r, s + 1, t, index + 1, str, res);
        }
    }
    else if (l > r && s == t)
    {
        if (l == n)
        {
            str.push_back(')');
            printParanthesis(n, m, l, r + 1, s, t, index + 1, str, res);
        }
        else
        {
            str.push_back('(');
            printParanthesis(n, m, l + 1, r, s, t, index + 1, str, res);
            str.push_back(')');
            printParanthesis(n, m, l, r + 1, s, t, index + 1, str, res);
        }
    }
    else if (l == r && s > t)
    {
        if (s == m)
        {
            str.push_back('{');
            printParanthesis(n, m, l, r, s + 1, t, index + 1, str, res);
        }
        else
        {
            str.push_back('{');
            printParanthesis(n, m, l, r, s + 1, t, index + 1, str, res);
            str.push_back('}');
            printParanthesis(n, m, l, r, s, t + 1, index + 1, str, res);
        }
    }
    else if (l > r && s > t)
    {
        if (l == n)
        {
            str.push_back(')');
            printParanthesis(n, m, l, r + 1, s, t, index + 1, str, res);
        }
        else
        {
            str.push_back('(');
            printParanthesis(n, m, l + 1, r, s, t, index + 1, str, res);
            str.push_back(')');
            printParanthesis(n, m, l, r + 1, s, t, index + 1, str, res);
        }
        if (s == m)
        {
            str.push_back('}');
            printParanthesis(n, m, l, r, s, t + 1, index + 1, str, res);
        }
        else
        {
            str.push_back('{');
            printParanthesis(n, m, l, r, s + 1, t, index + 1, str, res);
            str.push_back('}');
            printParanthesis(n, m, l, r, s, t + 1, index + 1, str, res);
        }
    }
}
void generateParenthesis(int n)
{
    vector<string> res;
    vector<char> temp;
    printParanthesis(1, 2, 0, 0, 0, 0, 0, temp, res);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
}
int main()
{
    generateParenthesis(2);
}