#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    vector<int> v(10, 0);
    cin >> a >> b >> c;


    string s = to_string(a * b * c);
    for (int i = 0; i < s.length(); ++i)
    {
        int ans = s[i] - '0';
        v[ans]++;
    }
    for (int j = 0; j < 10; ++j)
    {
        cout << v[j] << "\n";
    }
    return 0;
}
