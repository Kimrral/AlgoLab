#include<vector>
#include<queue>
#include<cstring>
#include <algorithm>
using namespace std;
int dist[102][102];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int solution(vector<vector<int> > maps)
{
    memset(dist, -1, sizeof(dist));
    int answer = 0;
    int m = maps[0].size();
    int n = maps.size();
    queue<pair<int, int>> q;
    dist[0][0] = 0;
    q.push({0, 0});
    while(!q.empty()){
        const auto cur = q.front(); q.pop();
        for(int dir = 0; dir<4; ++dir){
            int nx = cur.first+dx[dir];
            int ny = cur.second+dy[dir];
            if(nx<0||ny<0||nx>=n||ny>=m) continue;
            if(dist[nx][ny]>=0 || maps[nx][ny]!=1) continue;
            dist[nx][ny] = dist[cur.first][cur.second] +1;
            q.push({nx, ny});
        }
    }
    if(dist[n-1][m-1]==-1) return -1;
    answer = dist[n-1][m-1]+1;
    
    return answer;
}