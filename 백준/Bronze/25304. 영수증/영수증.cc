#include <iostream>
using namespace std;

int main() {
    int X; 
    cin >> X;

    int N;
    cin >> N; 

    int total = 0; 
    for (int i = 0; i < N; ++i) {
        int A, B;  
        cin >> A >> B;  
        total += A * B; 
    }

    if (total == X) {
        cout << "Yes" << endl; 
    } else {
        cout << "No" << endl;  
    }

    return 0;
}
