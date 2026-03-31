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
    vector<int> ans1(n, 0), ans2(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        ans1[i] = st.empty() ? 0 : st.top() + 1;
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        ans2[i] = st.empty() ? n + 1 : st.top() + 1;
        st.push(i);
    }
    // for (int x : ans1) cout << x << ' ';
    // cout << endl;
    // for (int x : ans2) cout << x << ' ';
    // cout << endl << endl;

    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, 
            (ans2[i] - ans1[i] - 1) * a[i]
        );
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
