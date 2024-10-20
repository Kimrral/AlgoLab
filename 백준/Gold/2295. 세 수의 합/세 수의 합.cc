#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> two(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            two.push_back(v[i] + v[j]);
        }
    }

    sort(two.begin(), two.end());

    for (int i = n - 1; i > 0; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (binary_search(two.begin(), two.end(), v[i] - v[j]))
            {
                cout << v[i];
                return 0;
            }
        }
    }
}
