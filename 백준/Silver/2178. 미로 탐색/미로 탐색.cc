#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
string board[102];
int dist[102][102];
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
        cin >> board[i];
    }

    memset(dist, -1, sizeof(dist));

    queue<pair<int, int>> q;
    dist[0][0] = 0;
    q.push({0, 0});
    while (!q.empty())
    {
        const auto cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (dist[nx][ny] >= 0 || board[nx][ny] != '1') continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
    cout << dist[n - 1][m - 1] + 1;
}
