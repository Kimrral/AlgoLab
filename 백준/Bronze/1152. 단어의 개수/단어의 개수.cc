#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);

    int count = 0;
    bool inWord = false; 

    for (const char c : s) {
        if (c != ' ') {
            if (!inWord) {
                inWord = true;
                count++;
            }
        } else {
            inWord = false; 
        }
    }

    cout << count << "\n"; 
    return 0;
}