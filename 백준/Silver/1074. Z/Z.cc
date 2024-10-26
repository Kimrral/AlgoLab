#include <iostream>
using namespace std;
int zOrder(int n, int r, int c){
    if(n==0) return 0;
    int half = 1<< (n-1);
    
    if(r<half && c<half){
        return zOrder(n-1, r, c);
    } else if(r<half && c>=half){
        return half * half+ zOrder(n-1, r, c-half);
    } else if(r>=half && c<half){
        return 2*half*half+zOrder(n-1, r-half, c);
    } else{
        return 3* half* half+ zOrder(n-1, r-half, c-half);
    }
}

int main(){
    int n, c, r;
    cin>>n>>r>>c;
    cout<<zOrder(n, r, c) <<endl;
    return 0;
}