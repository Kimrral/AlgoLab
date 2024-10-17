#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    int max = *max_element(v.begin(), v.end());
    double sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += ((double)v[i] / max) * 100;
    }

    cout << sum / n;
}
