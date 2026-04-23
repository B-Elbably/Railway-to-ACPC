#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int fastpow(int a, int b, int mod) {
    int res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = (__int128)res * a % mod;
        a = (__int128)a * a % mod;
        b >>= 1;
    }
    return res;
}
void solve() {
    int n, m, mod;
    cin >> n >> m >> mod;
    // map<int, vector<int>> mp;
    unordered_map<int, vector<int>> mp;
    mp.reserve(1 << 20);
    for (int i = 0; i < 100000; i++) {
        vector<int> res;
        int nx = n;
        for (int j = 0; j < 100; ++j) {
            int op = rng() % 3 + 1;
            if (op == 1) {
                res.push_back(1);
                nx = (nx + 1) % mod;
            }else if (op == 2) {
                res.push_back(2);
                nx = ((nx - 1) % mod + mod) % mod;
            } else {
                res.push_back(3);
                nx = fastpow(nx, mod - 2, mod);
            }
            if (nx == m) {
                cout << res.size() << endl;
                for (int x : res) cout << x << " ";
                return;
            }
        }
        mp[nx] = res;
    }
    for (int i = 0; i < 100000; i++) {
        vector<int> res;
        int nx = m;
        for (int j = 0; j < 100; ++j) {
            int op = rng() % 3 + 1;
            res.push_back(op);
            if (op == 2) {
                nx = (nx + 1) % mod;
            }else if (op == 1) {
                nx = ((nx - 1) % mod + mod) % mod;
            }else {
                res[res.size() - 1] = 3;
                nx = fastpow(nx, mod - 2, mod);
            }
            if (nx == n) {
                reverse(all(res));
                cout << res.size() << endl;
                for (int x : res) cout << x << " ";
                return;
            }
            if (mp.count(nx)) {
                auto &res2 = mp[nx];
                cout << res.size() + res2.size() << endl;
                for (int x : res2) cout << x << " ";
                reverse(all(res));
                for (int x : res) cout << x << " ";
                return;
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
