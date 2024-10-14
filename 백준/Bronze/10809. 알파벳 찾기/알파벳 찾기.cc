#include <iostream>
#include <cstring>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int count[26];
    memset(count, -1, sizeof(count));

    for (int i = 0; i < s.length(); ++i)
    {
        if (count[s[i] - 'a'] == -1)
            count[s[i] - 'a'] = i;
    }

    for (int i = 0; i < 26; ++i)
    {
        cout << count[i] << " ";
    }
}
