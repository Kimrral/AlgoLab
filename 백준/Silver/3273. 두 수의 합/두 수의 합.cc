#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

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

    int count = 0;    
    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        int sum = v[i] + v[j];
        if (sum == x)
        {
            count++;
            i++;
            j--;
        }
        else if (sum < x)
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    cout << count << "\n";
    return 0;
}
