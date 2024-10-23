#include <queue>
#include <string>
#include <vector>

using namespace std;
bool visited[202];

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    queue<int> q;
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;
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
                        visited[j] = true;
                        q.push({j});
                    }
                }
            }
        }
    }
    return answer;
}
