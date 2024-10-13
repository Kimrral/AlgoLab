#include <iostream>
using namespace std;
int board[8];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int count = 0;
    for (int i = 0; i < 8; ++i)
    {
        cin >> board[i];
    }

    for (int i = 0; i < 8; ++i)
    {
        if (board[i] < board[i + 1])
        {
            count++;
        }
    }

    if (count == 7)
    {
        cout << "ascending";
    }
    else if (count == 0)
    {
        cout << "descending";
    }
    else
    {
        cout << "mixed";
    }
}
