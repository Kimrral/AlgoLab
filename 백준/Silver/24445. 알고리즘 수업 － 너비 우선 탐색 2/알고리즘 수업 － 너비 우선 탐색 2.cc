#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<int> graph[100002];
int visited[100002];

int n, m, r;

int main()
{
    queue<int> q;
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
        sort(graph[i].begin(), graph[i].end(), greater<int>());
    }

    int count = 0;
    visited[r] = ++count;
    q.push(r);
    while (!q.empty())
    {
        const auto cur = q.front();
        q.pop();
        for (const auto nxt : graph[cur])
        {
            if (!visited[nxt])
            {
                visited[nxt] = ++count;
                q.push(nxt);
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << visited[i] << "\n";
    }
}
