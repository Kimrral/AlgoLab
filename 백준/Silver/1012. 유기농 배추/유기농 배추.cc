#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int board[51][51];
bool visited[51][51];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        queue<pair<int, int>> q;

        int m, n, k;
        cin >> m >> n >> k;
        memset(board, 0, sizeof(board));
        memset(visited, false, sizeof(visited));
        
        for (int i = 0; i < k; ++i)
        {
            int a, b;
            cin >> a >> b;
            board[b][a] = 1;
        }

        int count = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (visited[i][j] || board[i][j] != 1) continue;
                visited[i][j] = true;
                q.push({i, j});
                count++;
                
                while (!q.empty())
                {
                    const auto cur = q.front();
                    q.pop();
                    for (int dir = 0; dir < 4; ++dir)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if (visited[nx][ny] || board[nx][ny] != 1) continue;
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }

        cout << count << "\n";
    }
}
