#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<int> graph[102];
int visited[102];
int n, m;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    queue<int> q;
    visited[1] = 1;
    q.push(1);
    
    while (!q.empty())
    {
        const auto cur = q.front();
        q.pop();
        for (const auto nxt : graph[cur])
        {
            if (!visited[nxt])
            {
                visited[nxt] = 1;
                q.push(nxt);
            }
        }
    }
    
    int answer = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (visited[i] == 1)
        {
            answer++;
        }
    }

    cout << answer -1;
}
