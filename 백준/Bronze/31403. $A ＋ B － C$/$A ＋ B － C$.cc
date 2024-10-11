#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    cout << a + b - c << "\n";

    string a1 = to_string(a);
    string b1 = to_string(b);

    int sum = stoi(a1 + b1);


    cout << sum - c << "\n";
}
