#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    int cur = k;
    int count = 0;
    for (int j = n - 1; j >= 0; --j)
    {
        if (v[j] <= cur)
        {
            count += cur / v[j];
            cur %= v[j];
        }
    }

    cout << count;
}
