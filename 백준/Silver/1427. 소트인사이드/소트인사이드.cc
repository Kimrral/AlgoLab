#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;

    string s = to_string(n);
    sort(s.begin(), s.end(), greater<int>());
    cout << stoi(s);
}
