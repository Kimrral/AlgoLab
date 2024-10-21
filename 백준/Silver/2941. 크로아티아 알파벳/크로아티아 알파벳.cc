#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cin >> input;
    
    string croatian[] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    
    for (int i = 0; i < 8; i++) {
        while (true) {
            size_t pos = input.find(croatian[i]);
            if (pos == string::npos)
                break;
            input.replace(pos, croatian[i].length(), "1"); 
        }
    }

    cout << input.length() << endl;

    return 0;
}
