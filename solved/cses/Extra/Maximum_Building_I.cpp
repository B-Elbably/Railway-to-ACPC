#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int calc(int n, vector<int>& a) {
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
    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, (ans2[i] - ans1[i] - 1) * a[i]);
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> heights(m, 0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == '.') {
                heights[j]++;
            } else {
                heights[j] = 0;
            }
        }
        ans = max(ans, calc(m, heights));
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}