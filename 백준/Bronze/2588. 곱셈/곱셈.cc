#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    int B1 = B % 10;       
    int B10 = (B / 10) % 10; 
    int B100 = B / 100;      

    cout << A * B1 << endl; 
    cout << A * B10 << endl; 
    cout << A * B100 << endl; 
    cout << A * B << endl;    

    return 0;
}
