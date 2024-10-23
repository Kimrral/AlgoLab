#include <queue>
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> numbers, int target)
{
    int answer = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty())
    {
        const auto cur = q.front();
        int sum = cur.first;
        int index = cur.second;
        q.pop();
        if (index == numbers.size())
        {
            if (sum == target)
            {
                answer++;
            }
            continue;
        }
        q.push({sum + numbers[index], index + 1});
        q.push({sum - numbers[index], index + 1});
    }

    return answer;
}
