#include <iostream>
using namespace std;

int main() {
    int H, M, K;
    cin >> H >> M;  
    cin >> K;     

    M += K;  

    if (M >= 60) {
        H += M / 60;  
        M %= 60;      
    }

    if (H >= 24) {
        H %= 24; 
    }

    cout << H << " " << M << endl; 
    return 0;
}
