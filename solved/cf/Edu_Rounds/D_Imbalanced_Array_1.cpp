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
    vector<int> mnL(n), mnR(n);
    vector<int> mxL(n), mxR(n);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.top()] > a[i]) st.pop();
        mnL[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        mnR[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.top()] < a[i]) st.pop();
        mxL[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        mxR[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += a[i] * (i - mxL[i]) * (mxR[i] - i);
        ans -= a[i] * (i - mnL[i]) * (mnR[i] - i);
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
