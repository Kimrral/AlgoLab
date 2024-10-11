#include <queue>
#include<vector>
#include <cstring>
using namespace std;

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    int dist[n][m];
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
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
            if (dist[nx][ny] >= 0 || maps[nx][ny] != 1) continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
    
    if (dist[n-1][m-1] == -1)
    {
        return -1;
    }
    
    answer = dist[n-1][m-1]+1;

    return answer;
}
