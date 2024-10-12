#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    for (char a = 'a'; a <= 'z'; ++a)
    {
        int count = 0;
        for (const auto c : s)
        {
            if (a == c)
            {
                count++;
            }
        }
        cout << count << '\n';
    }
}
