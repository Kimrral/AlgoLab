#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compare(const pair<pair<int, string>, int>& a, const pair<pair<int, string>, int>& b)
{
    if (a.first.first == b.first.first)
    {
        return a.second < b.second;
    }
    return a.first.first < b.first.first;
}

int main()
{
    int n;
    cin >> n;

    vector<pair<pair<int, string>, int>> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i;
    }

    sort(v.begin(), v.end(), compare);

    for (const auto a : v)
    {
        cout << a.first.first << " " << a.first.second << "\n";
    }
}
