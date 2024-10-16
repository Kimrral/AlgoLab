#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
string board[30];
int visited[30][30];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int n;
vector<int> answer;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int count = 0;

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> board[i];
    }

    queue<pair<int, int>> q;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int area = 0;
            if (visited[i][j] != 0 || board[i][j] != '1') continue;
            count++;
            visited[i][j] = 1;
            q.push({i, j});
            while (!q.empty())
            {
                const auto cur = q.front();
                q.pop();
                area++;
                for (int dir = 0; dir < 4; ++dir)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if (visited[nx][ny] != 0 || board[nx][ny] != '1') continue;
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
            answer.push_back(area);
        }
    }

    sort(answer.begin(), answer.end());

    cout << count << "\n";

    for (const auto v : answer)
    {
        cout << v << "\n";
    }
}
