#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compare(const string& a, const string& b)
{
    if (a.length() == b.length())
    {
        return a < b;
    }
    return a.length() < b.length();
}

int main()
{
    int n;
    cin >> n;

    vector<string> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), compare);
    v.erase(unique(v.begin(), v.end()), v.end());

    for (const auto& c : v)
    {
        cout << c << "\n";
    }
}
