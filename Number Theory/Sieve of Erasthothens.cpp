#include <bits/stdc++.h>
using namespace std;

//complexity = O(n*log(log(n)))
void sieve(int n)
{
    vector<int> prime(n + 1, 1);
    prime[0] = 0, prime[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            for (int j = 2; i * j <= n; j++)
                prime[i * j] = 0;
        }
    }
}

int main()
{
    int n = 50;
    sieve(n);
}