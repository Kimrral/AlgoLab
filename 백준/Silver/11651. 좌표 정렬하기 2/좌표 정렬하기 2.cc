#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool compare(const pair<int, int> &a, const pair<int, int > &b)
{
    if(a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), compare);

    for (const auto a : v)
    {
        cout << a.first << " " << a.second << "\n";
    }
}
