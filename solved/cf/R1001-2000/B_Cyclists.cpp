#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k, p, m;
    cin >> n >> k >> p >> m;
    p--;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    priority_queue<int, vector<int>, greater<int>> pq;
    queue<int> q;
    int pp = k - (p < k);
    for (int i = 0; i < n; i++) {
        if (i == p) continue;
        if (pq.size() < pp) pq.push(a[i]);
        else {
            q.push(a[i]);
        }
    }
    int idx = p;
    int ans = 0;
    while (m >= 0) {
        if (idx < k) {
            m -= a[p];
            if (m < 0) break;
            ans++;
            idx = n - 1;
        } else {
            idx--;
            m -= pq.top();
            if (m < 0) break;
            q.push(pq.top()); pq.pop();
        }
        if (idx >= k) {
            pq.push(q.front());
            q.pop();
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}