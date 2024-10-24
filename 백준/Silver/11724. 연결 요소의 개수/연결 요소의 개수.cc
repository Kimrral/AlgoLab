#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int visited[1002];

void bfs(int start, vector<int> graph[]) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (const auto &nxt : graph[cur]) {
            if (!visited[nxt]) {
                visited[nxt] = 1;
                q.push(nxt);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> graph[n + 1]; 
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            bfs(i, graph);
            answer++;
        }
    }

    cout << answer << "\n";
    return 0;
}
