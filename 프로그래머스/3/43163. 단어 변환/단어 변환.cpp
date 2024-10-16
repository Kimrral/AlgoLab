#include <string>
#include <vector>
#include <queue>

using namespace std;

bool CanConvert(string& instr, string& nxtstr)
{
    int count = 0;
    for (int i = 0; i < instr.length(); ++i)
    {
        if (instr[i] != nxtstr[i])
        {
            count++;
        }
    }
    if (count == 1)
    {
        return true;
    }
    return false;
}

int solution(string begin, string target, vector<string> words)
{
    queue<pair<string, int>> q;
    int n = words.size();
    vector<bool> visited(n, false);

    q.push({begin, 0});

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        if (cur.first == target) return cur.second;
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i] && CanConvert(words[i], cur.first))
            {
                visited[i] = true;
                q.push({words[i], ++cur.second});
            }
        }
    }

    return 0;
}
