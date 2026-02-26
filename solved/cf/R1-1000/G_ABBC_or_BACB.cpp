#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    string road; cin >> road;
    int n = road.size(), ans = 0, cnt = 0;
    vector<int> sm;
    bool ok = road[0] == 'B' || road[n - 1] == 'B';
    for (int i = 0; i < n; ++i) {
        if (road[i] == 'A'){
            cnt++;
        }else {
            if (i) ok |= road[i] == road[i - 1];
            if (cnt) sm.push_back(cnt);
            cnt = 0;
        }
    } 
    if (cnt) sm.push_back(cnt);
    sort(all(sm), greater<int>());
    if (!ok) sm.pop_back();
    for (int i = 0; i < sm.size(); ++i) ans += sm[i];
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}

// B A.... 
// A.... BB
// A.... B A.... B
