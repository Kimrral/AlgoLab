#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    string sa = to_string(a);
    string sb = to_string(b);
    reverse(sa.begin(), sa.end());
    reverse(sb.begin(), sb.end());
    int maxnum = max(stoi(sa), stoi(sb));
    cout << maxnum;
}
