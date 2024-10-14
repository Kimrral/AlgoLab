#include <iostream>
#include <vector>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int combo = 0;
        int sum = 0;
        string s;
        cin >> s;
        for (const auto c : s)
        {
            if (c == 'O')
            {
                combo++;
                sum += combo;
            }
            else
            {
                combo = 0;
            }
        }

        cout << sum << "\n";
    }
}
