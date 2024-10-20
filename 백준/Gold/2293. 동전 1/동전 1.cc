#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;

    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    vector<int> dp(t + 1, 0);
    dp[0] = 1; 

    for (int i = 0; i < n; ++i) {
        for (int j = coins[i]; j <= t; ++j) {
            dp[j] += dp[j - coins[i]];
        }
    }

    cout << dp[t] << "\n";
    return 0;
}
