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
    
    for(int i=1; i<=n; ++i)
    {
        q.push(i);
    }

    while(q.size()>1)
    {
        q.pop();
        const auto front = q.front();
        q.pop();
        q.push(front);
    }

    cout << q.front();
}
