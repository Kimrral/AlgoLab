#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int total = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += v[i];
        total += sum;
    }

    cout << total;
}
