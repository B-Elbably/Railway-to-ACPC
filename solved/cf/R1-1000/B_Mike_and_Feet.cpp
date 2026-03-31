#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    
    stack<int> st;
    vector<pair<int,int>> res;
    
    for (int i = 0; i <= n; i++) {
        int cur = (i == n) ? 0 : a[i];
        while (!st.empty() && a[st.top()] >= cur) {
            int idx = st.top();
            st.pop();
            int len = i - (st.empty() ? -1 : st.top()) - 1;
            res.push_back({a[idx], len});
        }
        st.push(i);
    }
    
    sort(all(res), [](auto &a, auto &b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    });
    
    int cnt = 0;
    for (auto [ai, len] : res) {
        if (len <= cnt) continue;
        for (int i = cnt + 1; i <= len; i++) {
            cout << ai << ' ';
        }
        cnt = len;
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}