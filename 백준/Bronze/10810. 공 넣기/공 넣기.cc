#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        for (int j = a - 1; j <= b - 1; ++j)
        {
            v[j] = c;
        }
    }

    for (const auto a : v)
    {
        cout << a << " ";
    }
}
