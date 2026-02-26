#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void brute(vector<int> a, int k) {
    int n = a.size();
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
        cout << "After round " << i + 1 << ": ";
        for (int i : a) cout << i << " ";
        cout << endl;
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    // brute(a, k);
    if (k >= n) {
        sort(all(a));
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        return;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k + 1; i++) {
        pq.push(a[i]);
    }
    vector<int> ans;
    for (int i = k + 1; i < n; i++) {
        ans.push_back(pq.top());
        pq.pop();
        pq.push(a[i]);
    }
    while (!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }
    for (int i : ans) cout << i << " ";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
