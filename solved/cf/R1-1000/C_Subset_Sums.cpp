#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int SQ = 317;
const int N = 1e5 + 5;

vector<int> heavy;
int sum[N], lazy[N];
int intersect[SQ][N];

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<vector<int>> sets(m);
    vector<int> status(m);
    for (int i = 0; i < m; ++i) {
        int k; cin >> k;
        for (int j = 0; j < k; ++j) {
            int x; cin >> x;
            sets[i].push_back(--x);
        }
        if (k >= SQ) heavy.push_back(i), status[i] = 1;
    }
    int sz = heavy.size();
    vector<bool> freq(n);
    for (int h = 0; h < sz; ++h) {
        int idx = heavy[h];
        for (int x : sets[idx]) {
            sum[idx] += a[x];
            freq[x] = true;
        }
        for (int i = 0; i < m; ++i) {
            int cnt = 0;
            for (int x : sets[i])
                if (freq[x]) cnt++;
            intersect[h][i] = cnt; 
        }
        for (int x : sets[idx]) freq[x] = false;
    }

    while (q--) {
        char type; cin >> type;
        int idx; cin >> idx; --idx;
        if (type == '?') {
            if (status[idx]) {
                cout << sum[idx] << endl;
            } else {
                int ans = 0;
                for (int x : sets[idx]) ans += a[x];
                for (int h = 0; h < sz; ++h) {
                    int i = heavy[h];
                    ans += lazy[i] * intersect[h][idx];
                }
                cout << ans << endl;
            }
        }else{
            int v; cin >> v;
            if (status[idx])
                lazy[idx] += v;
            else 
                for (int x : sets[idx]) a[x] += v;
            for (int h = 0; h < sz; ++h) {
                int i = heavy[h];
                sum[i] += v * intersect[h][idx];
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
