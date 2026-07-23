#include <bits/stdc++.h>
using namespace std;
#define int long long
mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

// map<pair<int,int>, int> mp;

int ask(int i, int j) {
    // if (mp.count({i, j})) return mp[{i, j}];
    cout << "? " << i << " " << j << "\n";
    cout.flush();
    int res; 
    cin >> res;
    // mp[{i, j}] = mp[{j, i}] = res;
    return res;
}

void solve() {
    int n; cin >> n;
    vector<int> order(n);
    iota(order.begin(), order.end(), 1);
    shuffle(order.begin(), order.end(), mt);
    int a = order[0], b = order[1];
    int ab = ask(a, b);
    vector<int> discarded;
    for (int k = 2; k < n; ++k) {
        int c = order[k];
        int bc = ask(b, c);
        if (ab < bc) {
            discarded.push_back(c);
        } else if (ab > bc) {
            discarded.push_back(a);
            a = c;
            ab = bc;
        } else {
            discarded.push_back(b);
            b = c;
            ab = ask(a, c);
        }
    }
    int idx = -1;
    for (int z : discarded) {
        int az = ask(a, z);
        int bz = ask(b, z);
        if (az < bz) { idx = a; break; }
        if (bz < az) { idx = b; break; }
    }
    if (idx == -1) idx = a;
    vector<int> ans(n + 1, 0);
    ans[idx] = 0;
    for (int i = 1; i <= n; ++i) {
        if (i == idx) continue;
        ans[i] = ask(i, idx);
    }

    cout << "! ";
    for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
    cout << "\n";
    cout.flush();
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}