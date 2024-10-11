#include <iostream>
using namespace std;

int main() {
    int year;
    cin >> year; 

    // 윤년 조건 검사
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        cout << "1" << endl; 
    } else {
        cout << "0" << endl;  
    }

    return 0;
}
