#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	int draws = n - (a + b);
	if (draws < 0) {
		cout << "NO" << "\n";
		return;
	}

	int k = n - draws;
	if (k && (a == 0 || b == 0)) {
		cout << "NO" << "\n";
		return;
	}

	cout << "YES" << "\n";
	for (int i = 1; i <= n; i++) { cout << i << " "; }
	cout << "\n";

	for (int i = 1; i <= k; i++) {
		int val = i + a;
		if (val > k) val -= k;
		cout << val << " ";
	}

	for (int i = k + 1; i <= n; i++) { cout << i << " "; }
	cout << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}

