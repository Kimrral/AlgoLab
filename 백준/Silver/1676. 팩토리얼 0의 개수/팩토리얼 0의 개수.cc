#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int count = 0;

    for (int i = 5; i <= n; i *= 5)
    {
        count += n / i;
    }

    cout << count << '\n';

    return 0;
}
