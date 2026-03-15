#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 1e6 + 5;
bool used[N];

void solve() {
    memset(used, 0, sizeof(used));
    int n; 
    cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        vector<int> ai(m);
        for (int j = 0; j < m; j++) cin >> ai[j];
        for (int j = m - 1; j >= 0; j--) {
            if (!used[ai[j]]) {
                used[ai[j]] = 1;
                a[i].push_back(ai[j]);
            }
        }
        for (int x : a[i]) used[x] = false; 
    }
    
    vector<int> ans;
    for (;;) {
        for (int i = 0; i < n; i++) {
            vector<int> ai;
            for (int x : a[i]) {
                if (!used[x]) ai.push_back(x);
            }
            a[i] = ai;
        }
        sort(all(a));
        int i = 0;
        for (i = 0; i < n; i++) {
            if (a[i].empty()) continue;
            for (int x : a[i]) {
                used[x] = 1;
                ans.push_back(x);
            }
            break;
        }
        if (i == n) break;
    }

    for (int x : ans) cout << x << " ";
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}