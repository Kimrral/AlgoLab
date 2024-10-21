#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> v(5);
    for (int i = 0; i < 5; ++i)
    {
        cin >> v[i];
    }

    int maxlength = 0;
    for(const auto& c : v)
    {
        int curlength = c.length();
        maxlength = max(maxlength, curlength);
    }

    for (int i = 0; i < maxlength; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if(v[j][i]!=' ' && i<v[j].length()) cout << v[j][i]; 
        }
    }

    return 0;
}
