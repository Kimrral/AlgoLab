#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int k = 1;
    int sum = 0;

    while (sum + k < N) {
        sum += k;
        k++;
    }

    int numerator, denominator;

    if (k % 2 == 0) {
        numerator = N - sum;
        denominator = k + 1 - numerator;
    } else {
        denominator = N - sum;
        numerator = k + 1 - denominator;
    }

    cout << numerator << "/" << denominator << endl;

    return 0;
}
