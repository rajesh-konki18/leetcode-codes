#include <iostream>
#include <climits>
using namespace std;
int main()
{
    // your code goes here
    long long int t;
    cin >> t;
    long long int inp, maxElement = LLONG_MIN, *inputs = new long long int[t];
    for (long long int i = 0; i < t; i++)
    {
        cin >> inp;
        inputs[i] = inp;
        maxElement = max(inp, maxElement);
    }
    long long int maxElement = 20;
    long long int *primes = new long long int[maxElement];
    long long int *noPrimes = new long long int[maxElement];
    primes[1] = 1;
    for (long long int i = 2; i * i <= maxElement; i++)
    {
        if (primes[i] == 0)
        {
            for (long long int j = i; i * j <= maxElement; j++)
            {
                primes[i * j] = 1;
            }
        }
    }
    long long int count = 0;
    for (long long int i = 0; i < maxElement; i++)
    {
        if (primes[i] == 1)
            count++;
        noPrimes[i] = count;
    }
    for (long long int i = 0; i < t; i++)
    {
        cout << noPrimes[inputs[i]];
    }

    return 0;
}