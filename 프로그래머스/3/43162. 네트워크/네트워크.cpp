#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    queue<int> q;
    vector<int> visited(n, 0);
    for (int i = 0; i < n; ++i)
    {        
        if (visited[i]) continue;        
        visited[i] = 1;
        q.push(i);
        answer++;
        while (!q.empty())
        {
            const auto cur = q.front();
            q.pop();
            for (int j = 0; j < n; ++j)
            {
                if (!visited[j] && computers[cur][j] == 1)
                {
                    visited[j] = 1;
                    q.push(j);
                }
            }
        }
    }

    return answer;
}
