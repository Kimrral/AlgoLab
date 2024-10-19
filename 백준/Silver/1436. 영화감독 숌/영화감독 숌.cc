#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    
    int count=0;
    int number = 666;
    
    while(true){
        if(to_string(number).find("666")!=string::npos){
            count++;
        }
        
        if(count==n){
            cout<<number;
            break;
        }
        
        number++;
    }
}