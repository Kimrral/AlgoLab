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

    int i = 0;
    int j = n - 1;
    int left = i;
    int right = j;
    int best = v[i] + v[j];

    while (i < j)
    {
        int cursum = v[i] + v[j];
        if (abs(cursum) < abs(best))
        {
            best = cursum;
            left = i;
            right = j;
        }
        
        if (cursum > 0)
        {
            j--;
        }
        
        else if (cursum < 0)
        {
            i++;
        }
        
        else
        {
            break;
        }
    }

    cout << v[left] << " " << v[right];
}
