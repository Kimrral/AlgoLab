#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string word;
    cin >> word;

    transform(word.begin(), word.end(), word.begin(), ::toupper);

    int freq[26] = {0};

    for (char c : word) {
        freq[c - 'A']++;
    }

    int maxCount = 0;
    char result = '?';
    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxCount) {
            maxCount = freq[i];
            result = 'A' + i;
        } else if (freq[i] == maxCount) {
            result = '?'; 
        }
    }

    cout << result << endl;
    return 0;
}
