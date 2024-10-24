#include <iostream>
#include <cstdio> 
using namespace std;

void hanoi(int n, int start, int end, int temp) {
    if (n == 1) {
        printf("%d %d\n", start, end);
        return;
    }
    hanoi(n - 1, start, temp, end);
    printf("%d %d\n", start, end);
    hanoi(n - 1, temp, end, start); 
}

int main() {
    int n;
    cin >> n;
    printf("%lld\n", (1LL << n) - 1);
    hanoi(n, 1, 3, 2);
    return 0;
}
