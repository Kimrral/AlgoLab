#include <iostream>
#include <vector>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 1; i <= n; ++i)
    {
        v[i-1] = i;
    }

    int idx = 0;
    cout << "<";

    while (v.size() > 1)
    {
        idx = (idx + k - 1) % v.size();
        cout << v[idx];
        v.erase(v.begin() + idx);
        if (v.size() > 0)
        {
            cout << ", ";
        }
    }
    cout << v[0] << ">\n";
    return 0;
}
