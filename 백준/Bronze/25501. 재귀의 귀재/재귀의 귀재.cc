#include <iostream>
#include <string>
using namespace std;

int count;

int recursion(const string& s, int left, int right) {
    count++;
    if (left >= right) return 1;
    else if (s[left] != s[right]) return 0;
    else return recursion(s, left + 1, right - 1);
}

int isPalindrome(const string& s) {
    return recursion(s, 0, s.length() - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        string s;
        cin >> s;

        count = 0;
        cout << isPalindrome(s) << " " << count << "\n";
    }

    return 0;
}
