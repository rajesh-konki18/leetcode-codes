#include <iostream>
#include <vector>
using namespace std;

bool isSame(int c1[26], int c2[26])
{
    for (int i = 0; i < 26; i++)
    {
        if (c1[i] != c2[i])
            return false;
    }
    return true;
}

bool isPermuationExists(string s1, string s2)
{
    int counter[26] = {0};
    int subCounter[26] = {0};
    long long int ws = s1.size();
    long long int s2Size = s2.size();
    if (ws > s2Size)
    {
        return false;
    }
    for (long long int i = 0; i < ws; i++)
    {
        counter[s1[i] - 'a']++;
        subCounter[s2[i] - 'a']++;
    }

    for (long long int i = 0; i < s2Size - ws; i++)
    {
        if (isSame(counter, subCounter))
            return true;
        subCounter[s2[i] - 'a']--;
        char temp = s2[i + ws];
        long long int index = temp - 'a';
        subCounter[index]++;
    }
    if (isSame(counter, subCounter))
        return true;

    return false;
}

void checkPermutations(long long quries)
{
    vector<bool> isExists;
    for (long long i = 0; i < quries; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        isExists.push_back(isPermuationExists(s1, s2));
    }
    for (long long int i = 0; i < isExists.size(); i++)
    {
        cout << isExists[i] << endl;
    }
}

int main()
{
    long long int n;
    cin >> n;
    checkPermutations(n);

    return 0;
}