#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> graph[100001];
int visited[100001];
int cnt;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, r;
    cin >> n >> m >> r;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    queue<int> q;
    q.push(r);
    visited[r] = ++cnt;
    while (!q.empty())
    {
        const auto cur = q.front();
        q.pop();
        for (int nxt : graph[cur])
        {
            if (!visited[nxt])
            {
                visited[nxt] = ++cnt;
                q.push(nxt);
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << visited[i] << '\n';
    }

    return 0;
}
