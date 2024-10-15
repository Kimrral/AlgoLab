#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

vector<int> graph[1002];
bool visited[1002];

void DFS(int start) {
    visited[start] = true; // 현재 정점을 방문 처리
    cout << start << " "; // 정점 출력

    for (int next : graph[start]) {
        if (!visited[next]) {
            DFS(next); // 방문하지 않은 정점에 대해 재귀적으로 DFS 호출
        }
    }
}

void BFS(int start) {
    queue<int> q;
    memset(visited, false, sizeof(visited)); // BFS 전에 방문 배열 초기화
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " "; // 정점 출력

        for (int next : graph[cur]) {
            if (!visited[next]) {
                visited[next] = true; // 방문 처리
                q.push(next); // 큐에 다음 정점 추가
            }
        }
    }
}

int main() {
    int n, m, v; // n: 정점 수, m: 간선 수, v: 시작 정점
    cin >> n >> m >> v;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // 그래프 정렬: 작은 번호부터 방문하기 위해
    for (int i = 1; i <= n; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    // DFS 탐색
    memset(visited, false, sizeof(visited)); // DFS 전에 방문 배열 초기화
    DFS(v);
    cout << "\n";

    // BFS 탐색
    BFS(v);
    cout << "\n";

    return 0;
}
