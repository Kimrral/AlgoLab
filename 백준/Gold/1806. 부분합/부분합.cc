#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s;
    cin>>n>>s;

    vector<int> v(n);
    for(int i=0; i<n; ++i)
    {
        cin>>v[i];
    }

    int minlength = n+1;
    int start = 0;
    int end = 0;
    int sum = 0;
    while (true)
    {
        if(end>n)
        {
            break;
        }
        
        if(sum>=s)
        {
            minlength = min(minlength, end-start);
            sum-=v[start];
            start++;
        }
        else
        {
            sum+=v[end];
            end++;
        }
    }

    if(minlength == n+1)
    {
        cout<< 0;
    }
    else
    {
        cout<<minlength;
        return 0;
    }
}
