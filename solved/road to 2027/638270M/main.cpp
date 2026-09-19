#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct SparseTable {
	int n = 0;
	int K = 0;
	vector<int> lg;
	vector<vector<ll>> st;
	function<ll(ll, ll)> merge;

	SparseTable() {}

	SparseTable(const vector<ll>& a, function<ll(ll, ll)> op) {
		build(a, op);
	}

	void build(const vector<ll>& a, function<ll(ll, ll)> op) {
		merge = op;
		n = (int)a.size();
		if (n == 0) return;

		lg.assign(n + 1, 0);
		for (int i = 2; i <= n; ++i) lg[i] = lg[i >> 1] + 1;

		K = lg[n] + 1;
		st.assign(K, vector<ll>(n));
		for (int i = 0; i < n; ++i) st[0][i] = a[i];

		for (int k = 1; k < K; ++k) {
			int len = 1 << k;
			int half = len >> 1;
			for (int i = 0; i + len <= n; ++i) {
				st[k][i] = merge(st[k - 1][i], st[k - 1][i + half]);
			}
		}
	}

	ll query(int l, int r) const {
		int len = r - l + 1;
		int k = lg[len];
		return merge(st[k][l], st[k][r - (1 << k) + 1]);
	}
};

void solve() {
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	for (ll &x : a) cin >> x;
    for (ll &x : b) cin >> x;

	auto op = [](ll x, ll y) { return min(x, y); };
	SparseTable sp1(a, op);
    int l = 1, r = 1e9;
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + b[i];
    }
    ll res = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            if (a[i] < mid) continue;
            int L = i, R = n - 1;
            int idx = i - 1;
            while (L <= R) {
                int m = (L + R) / 2;
                if (sp1.query(i, m) >= mid) {
                    idx = m;
                    L = m + 1;
                } else {
                    R = m - 1;
                }
            }
            if (pref[idx + 1] - pref[i] >= mid) {
                ok = true;
                break;
            }
        }
        if (ok)res = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << 1ll * res * res << '\n';
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
	return 0;
}
