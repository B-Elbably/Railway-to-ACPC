#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> idx(n + 1, -1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        idx[a[i]] = i;
    }
    // vector<int> used(n + 1, 0);
    int mx = 3;
    stack<int> st;
    int ans = 0;
    int l = idx[3], r = idx[3];
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}


// 4 2 3 1