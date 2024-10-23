#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool exploreRoute(string loc, vector<vector<string>>& tktList, vector<bool>& usedTkt, vector<string>& route, int cnt) {
    route.push_back(loc);

    if (cnt == tktList.size()) {
        return true;
    }

    for (int idx = 0; idx < tktList.size(); idx++) {
        if (!usedTkt[idx] && tktList[idx][0] == loc) {
            usedTkt[idx] = true;
            if (exploreRoute(tktList[idx][1], tktList, usedTkt, route, cnt + 1)) {
                return true;
            }
            usedTkt[idx] = false;
        }
    }

    route.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tktList) {
    sort(tktList.begin(), tktList.end());

    vector<string> route;
    vector<bool> usedTkt(tktList.size(), false);

    exploreRoute("ICN", tktList, usedTkt, route, 0);

    return route;
}

int main() {
    vector<vector<string>> tktList1 = {{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}};
    vector<string> result1 = solution(tktList1);
    for (const string& loc : result1) {
        cout << loc << " ";
    }
    cout << endl;

    vector<vector<string>> tktList2 = {{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"}};
    vector<string> result2 = solution(tktList2);
    for (const string& loc : result2) {
        cout << loc << " ";
    }
    cout << endl;

    return 0;
}
