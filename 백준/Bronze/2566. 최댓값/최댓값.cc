#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> board(9, vector<int>(9));
    int maxelem = 0;
    int maxx = 0;
    int maxy = 0;
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] >= maxelem)
            {
                maxelem = board[i][j];
                maxx = i + 1;
                maxy = j + 1;
            }
        }
    }

    cout << maxelem << "\n";
    cout << maxx << " " << maxy;
}
