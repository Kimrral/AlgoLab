#include <iostream>
#include <vector>
using namespace std;
int maxindexnum = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> v;
    int maxelem = 0;
    for (int i = 0; i < 9; ++i)
    {
        int a;
        cin >> a;
        v.push_back(a);
        maxelem = max(maxelem, v[i]);
    }


    for (int i = 0; i < 9; ++i)
    {
        if (v[i] == maxelem)
        {
            maxindexnum = i;
        }
    }


    cout << maxelem << "\n" << maxindexnum + 1;
}
