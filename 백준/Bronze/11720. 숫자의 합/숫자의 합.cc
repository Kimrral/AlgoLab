#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string numbers;
    cin >> n >> numbers;

    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += numbers[i] - '0';
    }

    cout << sum << "\n";

    return 0;
}
