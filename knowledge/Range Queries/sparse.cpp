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
	vector<ll> a(n);
	for (ll &x : a) cin >> x;

	auto op = [](ll x, ll y) { return (x & y); };
	SparseTable sp(a, op);

	int q;
	cin >> q;
    int l, r;
	while (q--) {
		cin >> l >> r;
		cout << sp.query(--l, --r) << ' ';
    }
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}
