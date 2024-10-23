#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int board[102][102][102];
int days[102][102][102];
int dx[] = {1, 0, -1, 0, 0, 0};
int dy[] = {0, 1, 0, -1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n, h;
    cin >> m >> n >> h;

    queue<tuple<int, int, int>> q;
    memset(days, -1, sizeof(days));

    int count = 0;

    for (int i = 0; i < h; ++i) { 
        for (int j = 0; j < n; ++j) { 
            for (int k = 0; k < m; ++k) { 
                cin >> board[i][j][k];
                if (board[i][j][k] == 1) {
                    days[i][j][k] = 0; 
                    q.push({i, j, k});
                } else if (board[i][j][k] == 0) {
                    count++; 
                }
            }
        }
    }

    if (count == 0) { 
        cout << 0 << "\n"; 
        return 0;
    }

    while (!q.empty()) {
        const auto cur = q.front();
        q.pop();
        for (int dir = 0; dir < 6; ++dir) {
            int nx = get<0>(cur) + dx[dir];
            int ny = get<1>(cur) + dy[dir];
            int nz = get<2>(cur) + dz[dir];

            if (nx < 0 || ny < 0 || nz < 0 || nx >= h || ny >= n || nz >= m) continue;
            if (days[nx][ny][nz] != -1 || board[nx][ny][nz] != 0) continue;

            days[nx][ny][nz] = days[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1; 
            q.push({nx, ny, nz}); 
        }
    }

    int mindays = 0;  
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                if (days[i][j][k] == -1 && board[i][j][k]==0) { 
                    cout << -1 << "\n"; 
                    return 0;
                }
                mindays = max(mindays, days[i][j][k]); 
            }
        }
    }

    cout << mindays << "\n"; 
    return 0;
}
