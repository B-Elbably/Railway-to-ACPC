#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    map<int, int> length;   
    map<int, int> pos; 
    vector<int> parent(n, -1); 

    int ans = 0, idx = -1;
    for (int i = 0; i < n; i++) {
        int val = a[i];
        if (pos.count(val - 1)) {
            length[val] = length[val - 1] + 1;
            parent[i] = pos[val - 1];
        } else {
            length[val] = 1;
            parent[i] = -1;
        }

        pos[val] = i;
        if (length[val] > ans) {
            ans = length[val];
            idx = i;
        }
    }

    cout << ans << endl;
    vector<int> res;
    while (~idx) {
        res.push_back(idx + 1);
        idx = parent[idx];
    }
    
    reverse(all(res));
    for (auto &x : res) cout << x << " ";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}