#include <bits/stdc++.h>

using namespace std;
#define int long long

int difference[400005], widths[400005];
int interval_value[400005], prefix[400005];

vector<int> indices;
pair<int, int> queries[100005];
pair<pair<int, int>, int> updates[100005];

int compress(int a) {
	return lower_bound(indices.begin(), indices.end(), a) - indices.begin();
}

void solve() {
	int N, Q;
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		int l, r, v; cin >> l >> r >> v;
		indices.push_back(l);
		indices.push_back(r);
		updates[i] = {{l, r}, v};
	}
	for (int i = 0; i < Q; i++) {
		int l, r; cin >> l >> r;
		indices.push_back(l);
		indices.push_back(r);
		queries[i] = {l, r};
	}

	sort(indices.begin(), indices.end());
	indices.erase(unique(indices.begin(), indices.end()), indices.end());

	for (int i = 0; i < N; i++) {
		auto a = updates[i];
		difference[compress(a.first.first) + 1] += a.second;
		difference[compress(a.first.second) + 1] -= a.second;
	}

	for (int i = 0; i < indices.size() - 1; i++) {
		widths[i + 1] = indices[i + 1] - indices[i];
	}
    
	for (int i = 1; i < indices.size(); i++) {
        interval_value[i] = interval_value[i - 1] + difference[i];
		prefix[i] = prefix[i - 1] + interval_value[i] * widths[i];
	}

	for (int i = 0; i < Q; i++) {
		cout << prefix[compress(queries[i].second)] - prefix[compress(queries[i].first)] << "\n";
	}
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
