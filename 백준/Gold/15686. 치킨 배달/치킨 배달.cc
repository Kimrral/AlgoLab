#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define X first
#define Y second

int n, m, res = 1e9;
vector<pair<int, int>> v1, v2;

int dist(pair<int, int> a, pair<int, int> b) {
  return abs(a.X - b.X) + abs(a.Y - b.Y);
}

int chicken_dist(vector<pair<int, int>>& v3) {
  int sum = 0;
  for (auto h : v1) {
    int d = 1e9;
    for (auto c : v3) d = min(d, dist(h, c));
    sum += d;
  }
  return sum;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int r = 1; r <= n; r++) {
    for (int c = 1; c <= n; c++) {
      int num;
      cin >> num;
      if (num == 1) v1.push_back({r, c});
      else if (num == 2) v2.push_back({r, c});
    }
  }
  
  vector<int> v4(v2.size(), 1);
  fill(v4.begin(), v4.begin() + m, 0);
  
  do {
    vector<pair<int, int>> v3;
    for (int i = 0; i < v4.size(); i++) {
      if (!v4[i]) v3.push_back(v2[i]);
    }
    res = min(res, chicken_dist(v3));
  } while (next_permutation(v4.begin(), v4.end()));

  cout << res;
  return 0;
}
