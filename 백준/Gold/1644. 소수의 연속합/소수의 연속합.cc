#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> primes;
    for (int i = 2; i <= n; ++i)
    {
        if (isPrime(i))
        {
            primes.push_back(i);
        }
    }

    int start = 0;
    int end = 0;
    int sum = 0;
    int count = 0;
    while (true)
    {       
        if (sum >= n)
        {
            sum -= primes[start++];
        }
        else if(end==primes.size())
        {
            break;
        }
        else
        {
            sum += primes[end++];
        }

        if (sum == n)
        {
            count++;
        }
    }

    cout << count;
}
