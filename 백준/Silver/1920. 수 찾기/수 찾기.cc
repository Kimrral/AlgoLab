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
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int m;
    cin >> m;

    vector<int> v2(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> v2[i];
        if (binary_search(v.begin(), v.end(), v2[i]))
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
}
