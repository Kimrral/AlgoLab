#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long Factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * Factorial(n - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long answer = Factorial(n);
    cout << answer;
}
