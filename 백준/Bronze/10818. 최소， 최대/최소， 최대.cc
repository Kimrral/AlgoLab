#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> numbers[i];
    }

    auto maxelem = max_element(numbers.begin(), numbers.end());
    auto minelem = min_element(numbers.begin(), numbers.end());

    cout << *minelem << " " << *maxelem;

    return 0;
}
