#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false; 
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void findPrimes(const string& numbers, set<int>& uniquePrimes, string current, vector<bool>& visited) {
    if (!current.empty()) {
        int num = stoi(current);
        if (isPrime(num)) {
            uniquePrimes.insert(num);
        }
    }

    for (int i = 0; i < numbers.size(); ++i) {
        if (!visited[i]) {
            visited[i] = true;
            findPrimes(numbers, uniquePrimes, current + numbers[i], visited);
            visited[i] = false;
        }
    }
}

int solution(string numbers) {
    set<int> uniquePrimes;
    vector<bool> visited(numbers.size(), false);
    findPrimes(numbers, uniquePrimes, "", visited);
    return uniquePrimes.size();
}

