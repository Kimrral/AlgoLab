#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C; 

    if (A == B && B == C) {
        cout << 10000 + A * 1000 << endl; 
    }
    else if (A == B || A == C || B == C) {
        int same = (A == B) ? A : (A == C) ? A : B;
        cout << 1000 + same * 100 << endl;  
    }
    else {
        int max_value = max({A, B, C}); 
        cout << max_value * 100 << endl; 
    }

    return 0;
}
