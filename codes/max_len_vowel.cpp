#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool isVowel(char ch)
{
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

void getVowelLenght(long long int n)
{
    vector<long long int> result;
    for (long long int i = 0; i < n; i++)
    {
        string message;
        cin >> message;
        long long int k;
        cin >> k;
        long long int size = message.size();
        long long int vowelLen = 0;
        long long int ans = LLONG_MIN;
        for (long long int i = 0; i < k; i++)
        {
            if (isVowel(message[i]))
            {
                vowelLen++;
            }
        }
        ans = max(vowelLen, ans);
        vowelLen = ans;
        for (long long int i = k; message[i] != '\0'; i++)
        {
            if (isVowel(message[i]))
            {
                vowelLen++;
            }
            if (isVowel(message[i - k]))
            {
                vowelLen--;
            }
            ans = max(vowelLen, ans);
        }
        result.push_back(ans);
    }
    for (long long i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
}

int main()
{
    long long int n;
    cin >> n;
    getVowelLenght(n);
}