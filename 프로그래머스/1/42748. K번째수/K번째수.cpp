#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{    
    vector<int> answer2;
    for (int i = 0; i < commands.size(); ++i)
    {
        vector<int> answer;
        for (int k = commands[i][0]; k <= commands[i][1]; ++k)
        {
            answer.push_back(array[k-1]);
        }
        sort(answer.begin(), answer.end());
        answer2.push_back(answer[commands[i][2]-1]);
    }
    return answer2;
}
