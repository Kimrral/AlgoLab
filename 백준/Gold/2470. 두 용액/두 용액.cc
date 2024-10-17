#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int i = 0;
    int j = n - 1;
    int minsum = v[i] + v[j];
    int minleft = i;
    int minright = j;
    while (i < j)
    {
        auto cursum = v[i] + v[j];
        if (abs(cursum) < abs(minsum))
        {
            minsum = cursum;
            minleft = i;
            minright = j;
        }

        if (cursum < 0)
        {
            i++;
        }
        else if (cursum > 0)
        {
            j--;
        }
        else
        {
            break;
        }
    }

    cout << v[minleft] << " " << v[minright];
}
