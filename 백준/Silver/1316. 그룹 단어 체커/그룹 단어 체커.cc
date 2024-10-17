#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isGroupWord(const string& s) {
    vector<bool> seen(26, false);
    char lastChar = '\0';

    for (char c : s) {
        if (c != lastChar) {
            if (seen[c - 'a']) { 
                return false; 
            }
            seen[c - 'a'] = true;
            lastChar = c; 
        }
    }
    return true; 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int answer = 0;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        if (isGroupWord(s)) {
            answer++;
        }
    }

    cout << answer;
    return 0;
}
