#include <iostream>
#include <vector>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<vector<int>> v(t, vector<int>(3));

    for (int i = 0; i < t; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < t; ++i)
    {
        int row = (v[i][2] - 1) % v[i][0] + 1; 
        int col = (v[i][2] - 1) / v[i][0] + 1; 

        cout << row;
        if (col < 10)
        {
            cout << "0";
        }
        cout << col << "\n";
    }
}
