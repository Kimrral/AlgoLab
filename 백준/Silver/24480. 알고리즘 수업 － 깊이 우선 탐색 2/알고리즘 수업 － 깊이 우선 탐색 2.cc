#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
vector<int> graph[100002];
int visited[100002];
int cnt;
int n, m, r;

void DFS(int start)
{
    visited[start] = ++cnt;
    for (const auto nxt : graph[start])
    {
        if (!visited[nxt])
        {
            DFS(nxt);
        }
    }
}

int main()
{
    cin >> n >> m >> r;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
    {
        sort(graph[i].begin(), graph[i].end(), greater<int>());
    }

    DFS(r);

    for (int i = 1; i <= n; ++i)
    {
        cout << visited[i] << "\n";
    }
}
