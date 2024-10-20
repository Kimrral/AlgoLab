#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    queue<int> q;

    for (int i = 0; i < n; ++i)
    {
        string a;
        cin >> a;

        if (a == "push")
        {
            int value;
            cin >> value;
            q.push(value);
        }
        else if (a == "pop")
        {
            if (!q.empty())
            {
                cout << q.front() << "\n";
                q.pop();
            }
            else
            {
                cout << -1 << "\n";
            }
        }
        else if (a == "size")
        {
            cout << q.size() << "\n";
        }
        else if (a == "empty")
        {
            if (q.empty())
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        else if (a == "front")
        {
            if (q.empty())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << q.front() << "\n";
            }
        }
        else if (a == "back")
        {
            if (q.empty())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << q.back() << "\n";
            }
        }
    }
}
