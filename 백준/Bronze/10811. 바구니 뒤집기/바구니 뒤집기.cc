#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> v(n, 0);
    for (int i = 1; i <= n; ++i)
    {
        v[i - 1] = i;
    }
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;

        reverse(v.begin() + a - 1, v.begin() + b);
    }

    for (const auto a : v)
    {
        cout << a << " ";
    }
}
