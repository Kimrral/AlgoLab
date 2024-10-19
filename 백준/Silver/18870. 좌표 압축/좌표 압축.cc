#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> t(n);  
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        t[i] = v[i]; 
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for (int i = 0; i < n; ++i)
    {
        int compressed_value = lower_bound(v.begin(), v.end(), t[i]) - v.begin();
        cout << compressed_value << " ";
    }

    return 0;
}
