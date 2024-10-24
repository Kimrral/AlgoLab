#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int visited[102][102];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
queue<pair<int, int>> q;
int n, m;

int func(const vector<string>& board)
{
    int answer = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (!visited[i][j])
            {
                visited[i][j] = true;
                q.push({i, j});
                answer++;
                while (!q.empty())
                {
                    const auto cur = q.front();
                    q.pop();
                    for (int dir = 0; dir < 4; ++dir)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if (visited[nx][ny] != 0 || board[nx][ny] != board[cur.first][cur.second]) continue;
                        visited[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> board(102);
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> board[i];
    }

    m = board[0].length();
    int answer1 = func(board);

    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (board[i][j] == 'R')
            {
                board[i][j] = 'G';
            }
        }
    }

    int answer2 = func(board);

    cout << answer1 << " " << answer2 << "\n";
    return 0;
}
