#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    int start = 0;
    int end = 0;
    int sum = 0;
    int minlength = n + 1;
    while (true)
    {
        if (sum >= s)
        {
            minlength = min(minlength, end - start);
            sum -= v[start];
            start++;
        }
        else if (end == n)
        {
            break;
        }
        else
        {
            sum += v[end];
            end++;
        }
    }

    if (minlength == n + 1)
    {
        cout << 0;
        return 0;
    }
    else
    {
        cout << minlength;
        return 0;
    }
}
