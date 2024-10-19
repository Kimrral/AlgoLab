#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int maxsum = 0;

    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int sum = v[i] + v[j] + v[k];
              
                if (sum <= m && sum > maxsum) {
                    maxsum = sum;
                }
            }
        }
    }

    cout << maxsum << "\n";
    return 0;
}
