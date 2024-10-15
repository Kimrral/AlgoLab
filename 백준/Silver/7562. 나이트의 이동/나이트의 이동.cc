#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

bool visited[304][304];
int dx[] = {2, 2, 1, 1, -2, -2, -1, -1};
int dy[] = {1, -1, 2, -2, 1, -1, 2, -2};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int r;
        cin >> r;
        pair<int, int> a, b;
        cin >> a.first >> a.second;
        cin >> b.first >> b.second;

        memset(visited, false, sizeof(visited));

        queue<pair<int, int>> q;
        q.push({a.first, a.second});
        visited[a.first][a.second] = true;

        int count = 0;
        bool found = false;

        while (!q.empty() && !found)
        {
            int size = q.size();
            for (int j = 0; j < size; ++j)
            {
                const auto cur = q.front();
                q.pop();

                if (cur.first == b.first && cur.second == b.second)
                {
                    cout << count << "\n";
                    found = true;
                    break;
                }

                for (int dir = 0; dir < 8; ++dir)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx >= 0 && ny >= 0 && nx < r && ny < r && !visited[nx][ny])
                    {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
            count++;
        }
    }

    return 0;
}
