#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> listen(n);
    vector<string> see(m);
    vector<string> result;

    for (int i = 0; i < n; ++i) {
        cin >> listen[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> see[i];
    }

    sort(see.begin(), see.end());

    for (const auto& name : listen) {
        if (binary_search(see.begin(), see.end(), name)) {
            result.push_back(name);
        }
    }

    cout << result.size() << "\n";
    sort(result.begin(), result.end());
    for (const auto& name : result) {
        cout << name << "\n"; 
    }

    return 0;
}
