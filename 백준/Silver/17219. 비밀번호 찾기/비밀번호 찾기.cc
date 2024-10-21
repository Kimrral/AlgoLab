#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<string, string>> v(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < m; ++i)
    {
        string a;
        cin >> a;

        auto it = lower_bound(v.begin(), v.end(), make_pair(a, string()));

        if (it != v.end() && it->first == a)
        {
            cout << it->second << "\n";
        }
    }

    return 0;
}
