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
    vector<int> v2(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        v2[i] = v[i];
    }

    sort(v.begin(), v.end());

    v.erase(unique(v.begin(), v.end()), v.end());


    for (int i = 0; i < n; ++i)
    {
        int lower = lower_bound(v.begin(), v.end(), v2[i]) - v.begin();
        cout << lower << " ";
    }

    return 0;
}
