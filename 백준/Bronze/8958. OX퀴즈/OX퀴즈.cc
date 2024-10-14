#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        int sum = 0;
        int currentScore = 0;

        for (char c : s) {
            if (c == 'O') {
                currentScore++;  // O일 경우 점수 증가
                sum += currentScore; // 현재 점수를 합산
            } else {
                currentScore = 0; // O가 아닐 경우 점수 리셋
            }
        }
        cout << sum << "\n"; // 각 입력 문자열에 대한 총 점수 출력
    }

    return 0;
}
