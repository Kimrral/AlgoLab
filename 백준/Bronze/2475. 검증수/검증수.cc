#include <iostream>
#include <vector>
using namespace std;

int main() {
    int sum = 0;
    int number;

    for (int i = 0; i < 5; ++i) {
        cin >> number;
        sum += number * number;
    }

    cout << sum % 10;

    return 0;
}
