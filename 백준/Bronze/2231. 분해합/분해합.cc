#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    
    int minsum = 0;
    
    for(int i=1; i<=n; ++i){
            int num = i;
            int sum = 0;
            while(num!=0){
                sum += num%10;
                num/=10;
            }
        
            if(sum+i==n){
                minsum = i;
                break;
            }
    }
    
    if(minsum==0){
        cout<<0;
        return 0;
    }
    
    cout<<minsum;
}