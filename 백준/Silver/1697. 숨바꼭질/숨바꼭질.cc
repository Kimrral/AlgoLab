#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int dist[100002];
int n, k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    queue<int> q;
    memset(dist, -1, sizeof(dist));
    dist[n] = 0;
    q.push(n);
    while (!q.empty())
    {
        const auto cur = q.front();
        q.pop();
        int dir[] = {cur - 1, cur + 1, cur * 2};
        for (const auto nxt : dir)
        {
            if (dist[k] != -1)
            {
                cout << dist[k];
                return 0;
            }
            if (nxt > 100000 || nxt < 0) continue;
            if (dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }
}
