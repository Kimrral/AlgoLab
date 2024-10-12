#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    cin >> x;

    int stick = 64;
    int sum = stick;
    int count = 1;

    while (sum > x)
    {
        stick /= 2;

        if (sum - stick >= x)
        {
            sum -= stick;
        }
        else
        {
            count++; 
        }
    }

    cout << count << endl;
    return 0;
}
