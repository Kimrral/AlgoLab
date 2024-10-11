#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int board[502][502];
int dist[502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }

    memset(dist, -1, sizeof(dist));

    int num = 0;
    int maxarea = 0;

    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (dist[i][j] >= 0 || board[i][j] != 1) continue;
            num++;
            dist[i][j] = 0;
            q.push({i, j});
            int area = 0;
            while (!q.empty())
            {
                const auto cur = q.front();
                q.pop();
                area++;
                for (int dir = 0; dir < 4; ++dir)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if (dist[nx][ny] >= 0 || board[nx][ny] != 1) continue;
                    dist[nx][ny] = dist[cur.first][cur.second] + 1;
                    q.push({nx, ny});
                }
            }
            maxarea = max(maxarea, area);
        }
    }
    cout << num << "\n" << maxarea;
}
