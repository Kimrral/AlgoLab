#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<bool> submitted(31, false);
    vector<int> answer;
    for (int i = 0; i < 28; ++i)
    {
        int num = 0;
        cin >> num;
        submitted[num] = true;
    }

    for (int i = 1; i < submitted.size(); ++i)
    {
        if (!submitted[i])
        {
            answer.push_back(i);
        }
    }

    for (const auto a : answer)
    {
        cout << a << "\n";
    }
}
