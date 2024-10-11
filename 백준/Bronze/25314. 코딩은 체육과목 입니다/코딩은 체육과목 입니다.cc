#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    if (N > 0) {
        for (int i = 0; i < N / 4; ++i) {
            cout << "long ";  
        }
        cout << "int" << endl;  
    }

    return 0;
}
