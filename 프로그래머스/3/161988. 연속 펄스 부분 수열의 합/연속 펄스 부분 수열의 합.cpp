#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;

ll maxPulseSubsequenceSum(const vector<int>& sequence) {
    int n = sequence.size();

    // 첫 번째 펄스 수열 [1, -1, 1, -1, ...]
    ll maxSum1 = 0, currentSum1 = 0;
    for (int i = 0; i < n; ++i) {
        currentSum1 += (i % 2 == 0 ? sequence[i] : -sequence[i]);
        maxSum1 = max(maxSum1, currentSum1);
        if (currentSum1 < 0) {
            currentSum1 = 0; // reset if negative
        }
    }

    // 두 번째 펄스 수열 [-1, 1, -1, 1, ...]
    ll maxSum2 = 0, currentSum2 = 0;
    for (int i = 0; i < n; ++i) {
        currentSum2 += (i % 2 == 0 ? -sequence[i] : sequence[i]);
        maxSum2 = max(maxSum2, currentSum2);
        if (currentSum2 < 0) {
            currentSum2 = 0; // reset if negative
        }
    }

    return max(maxSum1, maxSum2);
}

ll solution(vector<int> sequence) {
    return maxPulseSubsequenceSum(sequence);
}
