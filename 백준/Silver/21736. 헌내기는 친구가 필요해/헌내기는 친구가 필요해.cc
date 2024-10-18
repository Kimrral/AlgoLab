#include <iostream>
#include <queue>
using namespace std;

int n, m;  // 캠퍼스의 크기 (n x m)
char campus[601][601];  // 캠퍼스 맵
bool visited[601][601];  // 방문 여부
int dx[] = {0, 0, 1, -1};  // 상하좌우 이동을 위한 x 좌표 변화
int dy[] = {1, -1, 0, 0};  // 상하좌우 이동을 위한 y 좌표 변화

int bfs(int startX, int startY) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;
    int friends = 0;  // 만난 친구의 수

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 상하좌우로 이동하면서 탐색
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위를 벗어나거나 벽('X')이거나 이미 방문한 경우는 건너뜀
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || campus[nx][ny] == 'X' || visited[nx][ny])
                continue;

            visited[nx][ny] = true;  // 방문 처리
            q.push({nx, ny});  // 다음 탐색 위치 큐에 삽입

            if (campus[nx][ny] == 'P')
                friends++;
        }
    }

    return friends;
}

int main() {
    cin >> n >> m;
    int startX, startY;

    // 캠퍼스 맵 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> campus[i][j];
            if (campus[i][j] == 'I') {  // 도연이의 시작 위치
                startX = i;
                startY = j;
            }
        }
    }

    // BFS 실행 후 친구의 수 출력
    int result = bfs(startX, startY);
    if (result == 0)
        cout << "TT";  // 친구를 만나지 못한 경우
    else
        cout << result;  // 만난 친구의 수 출력

    return 0;
}
