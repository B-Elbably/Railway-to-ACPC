#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 1e5 + 5;
const int INF = 1e18;
vector<int> a;
int n, l, s;

void solve() {
    cin >> n >> s >> l;
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int ans = 0;
    deque<int> mn, mx;
    int k = 1;
    vector<int> L(n + 1);
    for (int i = 1; i <= n; ++i) {
        while (!mn.empty() && a[mn.back()] >= a[i]) mn.pop_back();
        mn.push_back(i);
        while (!mx.empty() && a[mx.back()] <= a[i]) mx.pop_back();
        mx.push_back(i);
        while (a[mx.front()] - a[mn.front()] > s) {
            if (mn.front() == k) mn.pop_front();
            if (mx.front() == k) mx.pop_front();
            ++k;
        }
        L[i] = i - k + 1;
    }
    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    deque<int> dq;
    for (int i = 1; i <= n; ++i) {
        if (i >= l) {
            k = i - l;
            if (dp[k] != INF) {
                while (!dq.empty() && dp[dq.back()] >= dp[k]) dq.pop_back();
                dq.push_back(k);    
            }
        }
        while (!dq.empty() && dq.front() < i - L[i]) dq.pop_front();
        if (!dq.empty()) dp[i] = dp[dq.front()] + 1;
    }
    if (dp[n] == INF) dp[n] = -1;
    cout << dp[n] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
