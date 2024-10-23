#include <iostream>
#include <stdbool.h>
#include <vector>
using namespace std;

int whitecount;
int bluecount;

void paper(vector<vector<int>>& board, int x, int y, int num)
{
    int init = board[x][y];
    bool issame = true;
    for (int i = x; i < x + num; ++i)
    {
        for (int j = y; j < y + num; ++j)
        {
            if (init != board[i][j])
            {
                issame = false;
                break;
            }
        }
        if (!issame) break;
    }

    if (issame)
    {
        if (init == 1) bluecount++;
        else whitecount++;
    }
    else
    {
        paper(board, x, y, num / 2);
        paper(board, x + num / 2, y, num / 2);
        paper(board, x, y + num / 2, num / 2);
        paper(board, x + num / 2, y + num / 2, num / 2);
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
        }
    }

    paper(board, 0, 0, n);
    cout << whitecount << "\n" << bluecount;
}
