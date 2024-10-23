#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 102;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int map[MAX][MAX];
bool visited[MAX][MAX];

void drawRectangle(const vector<int>& rect) {
    for (int i = rect[0] * 2; i <= rect[2] * 2; i++) {
        for (int j = rect[1] * 2; j <= rect[3] * 2; j++) {
            if (i == rect[0] * 2 || i == rect[2] * 2 || j == rect[1] * 2 || j == rect[3] * 2) {
                if (map[i][j] != 2) map[i][j] = 1;
            } else {
                map[i][j] = 2;
            }
        }
    }
}

int bfs(int cx, int cy, int ix, int iy) {
    queue<pair<int, int>> q;
    queue<int> dist;

    q.push({cx, cy});
    dist.push(0);
    visited[cx][cy] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        int d = dist.front();

        q.pop();
        dist.pop();

        if (x == ix && y == iy) {
            return d / 2;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < MAX && ny >= 0 && ny < MAX && !visited[nx][ny] && map[nx][ny] == 1) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                dist.push(d + 1);
            }
        }
    }

    return -1;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    memset(map, 0, sizeof(map));
    memset(visited, false, sizeof(visited));

    for (const auto& rect : rectangle) {
        drawRectangle(rect);
    }

    return bfs(characterX * 2, characterY * 2, itemX * 2, itemY * 2);
}

int main() {
    vector<vector<int>> rectangle = {{1, 1, 7, 4}, {3, 2, 5, 5}, {4, 3, 6, 9}, {2, 6, 8, 8}};
    int characterX = 1, characterY = 3, itemX = 7, itemY = 8;
    cout << solution(rectangle, characterX, characterY, itemX, itemY) << endl;

    return 0;
}
