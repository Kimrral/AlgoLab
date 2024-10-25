#include <iostream>
#include <vector>

const int MOD = 15746;

int main() {
    int N;
    std::cin >> N;

    std::vector<int> dp(N + 1);
    dp[1] = 1;
    if (N >= 2) {
        dp[2] = 2;
    }

    for (int i = 3; i <= N; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    std::cout << dp[N] << std::endl;
    return 0;
}
