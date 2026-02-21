#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    sort(all(a));
    priority_queue<int, vector<int>, greater<int>> pq;

    int i = 0, L = 0;
    bool ok = true;

    while (i < n || !pq.empty()) {
        if (pq.empty()) L = max(L, a[i].first);
        for (;i < n && a[i].first == L; i++)  pq.push(a[i].second);

        if (pq.empty() || pq.top() < L) {
            ok = false;
            break;
        }
        pq.pop();
        L++;
    }

    cout << (ok ? "Yes" : "No") << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}
