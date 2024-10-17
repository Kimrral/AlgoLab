#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> listen(n);
    vector<string> see(m);
    vector<string> result; // 듣보잡의 결과를 저장할 벡터

    // 듣도 못한 사람들 입력
    for (int i = 0; i < n; ++i) {
        cin >> listen[i];
    }

    // 보도 못한 사람들 입력
    for (int i = 0; i < m; ++i) {
        cin >> see[i];
    }

    // 듣도 못한 사람들 정렬
    sort(listen.begin(), listen.end());
    // 보도 못한 사람들 정렬
    sort(see.begin(), see.end());

    // 교집합 찾기
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (listen[i] < see[j]) {
            ++i; // 듣도 못한 사람의 이름이 더 작으면 다음으로
        } else if (listen[i] > see[j]) {
            ++j; // 보도 못한 사람의 이름이 더 작으면 다음으로
        } else {
            result.push_back(listen[i]); // 두 이름이 같으면 결과에 추가
            ++i; // 다음으로
            ++j; // 다음으로
        }
    }

    // 결과 출력
    cout << result.size() << "\n"; // 교집합의 크기 출력
    for (const auto& name : result) {
        cout << name << "\n"; // 교집합의 이름 출력
    }

    return 0;
}
