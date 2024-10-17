#include <algorithm>
#include <iostream>
#include <vector>
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

    int x;
    cin >> x;

    int i = 0;
    int j = n - 1;
    int count = 0;
    while (i < j)
    {
        int sum = v[i] + v[j];
        if (sum == x)
        {
            count++;
            i++;
            j--;
        }
        else if (sum > x)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    cout << count;
}
