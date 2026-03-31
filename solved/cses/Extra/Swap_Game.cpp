#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

string cur;
int cnt;
queue<pair<string, int>> q;
unordered_set<string> vis;

void calc(int x, int y) {
    swap(cur[x], cur[y]);
    if (vis.find(cur) == vis.end()) {
        vis.insert(cur);
        q.push({cur, cnt + 1});
    }
    swap(cur[x], cur[y]);
}

void solve() {
    string s = "";
    int a;
    for (int i = 0; i < 9; i++) {
        cin >> a;
        s += to_string(a - 1);
    }
    q.push({s, 0});
    vis.insert(s);
    while (!q.empty()) {
        pair<string, int> p = q.front();
        cur = p.first; cnt = p.second;
        q.pop();
        if (cur == "012345678") {
            cout << cnt << endl;
            return;
        }
        for (int i = 0; i < 9; i+= 3) {
            calc(i, i + 1);
            calc(i + 1, i + 2);
        }
        for (int i = 0; i < 3; i++) {
            calc(i, i + 3);
            calc(i + 3, i + 6);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}