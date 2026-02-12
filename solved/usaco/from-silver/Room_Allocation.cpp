#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> go;
    for (int i = 0; i < n; i++) {cin >> a[i].first >> a[i].second; go.push({a[i].first, i});}
    set<int> valid;
    for (int i = 1; i <= n; i++) valid.insert(i);
    vector<int> res(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++) {
        int idx = go.top().second;
        go.pop();
        while (!pq.empty() && pq.top().first < a[idx].first) {
            valid.insert(pq.top().second);
            pq.pop();
        }
        pq.push({a[idx].second, *valid.begin()});
        res[idx] = *valid.begin();
        valid.erase(valid.begin());
    }
    cout << *max_element(all(res)) << endl;
    for (auto x : res) cout << x << " ";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
