#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int dist[1000002];
int previous[1000002]; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    memset(dist, -1, sizeof(dist));
    memset(previous, -1, sizeof(previous)); 

    queue<int> q;
    dist[n] = 0;
    q.push(n);

    while (!q.empty()) {
        const int cur = q.front();
        q.pop();

        if (cur == 1) {
            cout << dist[cur] << "\n";

            // 경로 출력
            vector<int> path;
            for (int i = cur; i != -1; i = previous[i]) { 
                path.push_back(i);
            }
            for (int i = path.size() - 1; i >= 0; i--) {
                cout << path[i] << " ";
            }
            return 0;
        }

        if (cur % 3 == 0 && dist[cur / 3] == -1) {
            dist[cur / 3] = dist[cur] + 1;
            previous[cur / 3] = cur; 
            q.push(cur / 3);
        }

        if (cur % 2 == 0 && dist[cur / 2] == -1) {
            dist[cur / 2] = dist[cur] + 1;
            previous[cur / 2] = cur; 
            q.push(cur / 2);
        }

        if (cur - 1 >= 0 && dist[cur - 1] == -1) {
            dist[cur - 1] = dist[cur] + 1;
            previous[cur - 1] = cur; 
            q.push(cur - 1);
        }
    }

    return 0;
}
