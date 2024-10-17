#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> board(102, vector<int>(102, 0));
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;

        for (int j = a; j < a + 10; ++j)
        {
            for (int k = b; k < b + 10; ++k)
            {
                board[j][k] = 1;
            }
        }
    }

    int answer = 0;
    for (const auto& elem : board)
    {
        for (const auto b : elem)
        {
            if (b == 1)
            {
                answer++;
            }
        }
    }

    cout << answer;
}
