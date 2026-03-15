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
    vector<int> back(n), go(n);
    stack<int> st;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        back[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.top()] < a[i]) st.pop();
        go[i] = st.empty() ? n : st.top();
        ans += a[i] * (i - back[i]) * (go[i] - i);
        st.push(i);
    }
    
    // for (int i = 0; i < n; ++i) cout << back[i] << " ";
    // cout << endl;
    // for (int i = 0; i < n; ++i) cout << go[i] << " ";
    // cout << endl;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        back[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.top()] > a[i]) st.pop();
        go[i] = st.empty() ? n : st.top();
        ans -= a[i] * (i - back[i]) * (go[i] - i);
        st.push(i);
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
