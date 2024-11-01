#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> arr;

void compress(int x, int y, int size) {
    int first = arr[x][y];
    bool same = true;

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (arr[i][j] != first) {
                same = false;
                break;
            }
        }
        if (!same) break;
    }

    if (same) {
        cout << first;
    } else {
        cout << "(";
        int half = size / 2;
        compress(x, y, half);             
        compress(x, y + half, half);       
        compress(x + half, y, half);       
        compress(x + half, y + half, half); 
        cout << ")";
    }
}

int main() {
    int n;
    cin >> n;
    arr.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < n; j++) {
            arr[i][j] = line[j] - '0';
        }
    }

    compress(0, 0, n);
    return 0;
}
