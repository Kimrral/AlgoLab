#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;

    stack<int> s;
    for (int i = 0; i < N; i++) {
        int command;
        cin >> command;
        
        if (command == 1) {
            int x;
            cin >> x;
            s.push(x);
        } else if (command == 2) {
            if (s.empty()) {
                cout << "-1\n";
            } else {
                cout << s.top() << "\n";
                s.pop();
            }
        } else if (command == 3) {
            cout << s.size() << "\n";
        } else if (command == 4) {
            cout << (s.empty() ? 1 : 0) << "\n";
        } else if (command == 5) {
            if (s.empty()) {
                cout << "-1\n";
            } else {
                cout << s.top() << "\n";
            }
        }
    }

    return 0;
}
