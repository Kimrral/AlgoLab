#include <iostream>
using namespace std;

int fib_count = 0;      
int dp_count = 0;       

int fib(int n) {
    if (n == 1 || n == 2) {
        fib_count++;  
        return 1;
    }
    else {
        return fib(n - 1) + fib(n - 2);
    }
}

int fibonacci(int n) {
    int dp[41];        
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp_count++;   
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
  
    fib(n);
 
    fibonacci(n);

    cout << fib_count << " " << dp_count << endl;

    return 0;
}
