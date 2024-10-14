#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> board(10);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int count = 0;

    for (int i = 0; i < 10; ++i)
    {
        cin >> board[i];
        board[i] %= 42;
    }

    sort(std::begin(board), std::end(board));
    board.erase(unique(board.begin(), board.end()), board.end());


    cout << board.size();
}
