#include <iostream>
#include <queue>
using namespace std;
int N, M;
int num[1001][1001] = {0};
int dist[1001][1001] = {0};
int targetx, targety;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int startx, int starty)
{
    queue<pair<int, int>> q;
    q.push({startx, starty});
    dist[startx][starty] = 1;
    while (!q.empty())
    {
        const auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M)
            {
                if (dist[nx][ny] == 0 && num[nx][ny] != 0)
                {
                    dist[nx][ny] = dist[cur.first][cur.second] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int a;
            cin >> a;
            if (a == 2)
            {
                targetx = i;
                targety = j;
            }
            num[i][j] = a;
        }
    }

    bfs(targetx, targety);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (num[i][j] == 0)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << dist[i][j] - 1 << " ";
            }
        }
        cout << "\n";
    }
}
