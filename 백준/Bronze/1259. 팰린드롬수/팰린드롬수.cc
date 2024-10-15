#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            return 0;
        }
        auto s = to_string(n);
        auto rs = s;
        reverse(rs.begin(), rs.end());
        if (rs == s)
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }
}
