#include <iostream>
using namespace std;
int getDigits(int num){
    int sum = 0;
    while(num!=0){
        sum += num%10;
        num/=10;
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    
    int i = 1;
    while(i<n){
        if(getDigits(i)+i == n){
            cout << i;
            return 0;
        }
        i++;
    }
    
    cout << 0;
    return 0;
}