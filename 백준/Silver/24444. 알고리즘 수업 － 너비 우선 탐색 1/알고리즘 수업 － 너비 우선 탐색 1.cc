#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[100002];
int visited[100002];
int n, m, r;
int cnt;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> r;
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    queue<int> q;
    visited[r] = ++cnt;
    q.push(r);
    while (!q.empty())
    {
        const auto cur = q.front();
        q.pop();
        for (const auto nxt : graph[cur])
        {
            if (visited[nxt] == 0)
            {
                visited[nxt] = ++cnt;
                q.push(nxt);
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << visited[i] << "\n";
    }
}
