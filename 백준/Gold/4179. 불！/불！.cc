#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
string board[1002];
int dist1[1002][1002];
int dist2[1002][1002];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    queue<pair<int, int>> q1;
    queue<pair<int, int>> q2;
    memset(dist1, -1, sizeof(dist1));
    memset(dist2, -1, sizeof(dist2));
    for (int i = 0; i < n; ++i)
    {
        cin >> board[i];
        for (int j = 0; j < m; ++j)
        {
            if (board[i][j] == 'F')
            {
                dist1[i][j] = 0;
                q1.push({i, j});
            }
            if (board[i][j] == 'J')
            {
                dist2[i][j] = 0;
                q2.push({i, j});
            }
        }
    }

    // Fire BFS
    while (!q1.empty())
    {
        const auto cur = q1.front();
        q1.pop();
        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
            q1.push({nx, ny});
        }
    }

    // Jihun BFS
    while (!q2.empty())
    {
        const auto cur = q2.front();
        q2.pop();
        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            // 탈출 지점 도착
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            {
                cout << dist2[cur.first][cur.second] +1;
                return 0;
            }
            if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.first][cur.second] + 1) continue;
            dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
            q2.push({nx, ny});
        }
    }
    
    cout << "IMPOSSIBLE";
    return 0;
}
