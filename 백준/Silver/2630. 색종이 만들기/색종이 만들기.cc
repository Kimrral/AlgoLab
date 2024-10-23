#include <iostream>
#include <vector>
using namespace std;

int white_count = 0;
int blue_count = 0;

void countPapers(const vector<vector<int>>& paper, int x, int y, int size) {
    int color = paper[x][y];
    bool sameColor = true;

    for (int i = x; i < x + size; ++i) {
        for (int j = y; j < y + size; ++j) {
            if (paper[i][j] != color) {
                sameColor = false;
                break;
            }
        }
        if (!sameColor) break;
    }

    if (sameColor) {
        if (color == 0) white_count++;
        else blue_count++;
    } else {
        int newSize = size / 2;
        countPapers(paper, x, y, newSize);
        countPapers(paper, x, y + newSize, newSize);
        countPapers(paper, x + newSize, y, newSize);
        countPapers(paper, x + newSize, y + newSize, newSize);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> paper(N, vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> paper[i][j];
        }
    }

    countPapers(paper, 0, 0, N);
    cout << white_count << "\n" << blue_count << "\n";
    return 0;
}
