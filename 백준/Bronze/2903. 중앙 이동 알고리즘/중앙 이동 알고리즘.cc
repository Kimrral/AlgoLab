#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int side = 2;
    int dots = 4;
    
    for(int i=0; i<n; ++i)
    {
        side = side + (side-1);        
    }

    dots = side * side;

    cout << dots;
}
