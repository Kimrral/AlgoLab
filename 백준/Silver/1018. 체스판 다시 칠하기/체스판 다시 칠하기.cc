#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int compare(const vector<string>& board, const int x, const int y) {
    int count1 = 0; // 'W'로 시작하는 경우
    int count2 = 0; // 'B'로 시작하는 경우

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            char expectedColor1 = ((i + j) % 2 == 0) ? 'W' : 'B'; // 패턴 1: 'W' 시작
            char expectedColor2 = ((i + j) % 2 == 0) ? 'B' : 'W'; // 패턴 2: 'B' 시작

            if (board[x + i][y + j] != expectedColor1) {
                count1++;
            }
            if (board[x + i][y + j] != expectedColor2) {
                count2++;
            }
        }
    }
    return min(count1, count2); // 두 패턴 중 최소값 반환
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> board(n);
    for (int i = 0; i < n; ++i) {
        cin >> board[i];
    }

    int mincount = 64; // 최대 불일치 수 (8x8 보드의 모든 칸이 불일치)

    for (int i = 0; i <= n - 8; ++i) { // 범위 조건 수정
        for (int j = 0; j <= m - 8; ++j) { // 범위 조건 수정
            mincount = min(compare(board, i, j), mincount); // 최소 불일치 수 갱신
        }
    } 

    cout << mincount;
    return 0;
}
