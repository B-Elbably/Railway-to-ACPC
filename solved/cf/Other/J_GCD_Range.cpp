#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
int LOG2[N];
void build() {
    for (int i = 2; i < N; i++)
        LOG2[i] = LOG2[i/2] + 1;
}
int fast_power(int base, int exp) {
    int res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

struct Sparse {
    int n, LOG;
    vector<vector<int>> st;

    Sparse(vector<int> &a) {
        n = a.size();
        LOG = LOG2[n] + 1;

        st.assign(LOG, vector<int>(n)); 
        st[0] = a;

        for (int k = 1; k < LOG; k++)
            for (int i = 0; i + (1 << k) <= n; i++)
                st[k][i] = gcd(st[k-1][i], st[k-1][i + (1<<(k-1))]);
    }

    int query(int i, int r) {
        int k = LOG2[r - i + 1];
        return gcd(st[k][i], st[k][r - (1<<k) + 1]);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    // gcd same or less "A wise man said"- MinValgen
    int inv = fast_power(2, MOD - 2);
    Sparse st(a);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int idx = i;
        while (idx < n) {
            int gc = st.query(i, idx);
            int l = idx, r = n - 1;
            int best = idx;

            while (l <= r) {
                int mid = (l + r) / 2;
                if (st.query(i, mid) == gc) {
                    best = mid;
                    l = mid + 1;
                } else r = mid - 1;
            }

            int L = idx - i + 1;
            int R = best - i + 1;

            int sum = (L + R) * (best - idx + 1); sum %= MOD;
            sum *= inv % MOD;
            sum %= MOD;

            ans += gc % MOD * sum % MOD; ans %= MOD;
            idx = best + 1;
        }
    }

    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    build();
    int t = 1;
    cin >> t;
    while (t--) solve();
}