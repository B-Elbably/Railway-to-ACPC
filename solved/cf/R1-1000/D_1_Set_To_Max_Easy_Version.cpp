#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    vector<int> L(n), R(n), st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && b[st.back()] >= b[i] && a[st.back()] <= b[i]) {
            st.pop_back();
        }
        L[i] = st.empty() ? 0 : st.back() + 1;
        st.push_back(i);
    }
    st.clear();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && b[st.back()] >= b[i] && a[st.back()] <= b[i]) {
            st.pop_back();
        }
        R[i] = st.empty() ? n - 1 : st.back() - 1;
        st.push_back(i);
    }

    vector<int> last(n + 1, -1);
    vector<bool> ok(n, false);
    for (int i = 0; i < n; i++) {
        last[a[i]] = i;
        if (last[b[i]] >= L[i]) ok[i] = true;
    }
    fill(all(last), -1);
    for (int i = n - 1; i >= 0; i--) {
        last[a[i]] = i;
        if (last[b[i]] != -1 && last[b[i]] <= R[i]) ok[i] = true;
    }

    for (int i = 0; i < n; i++) {
        if (!ok[i] || a[i] > b[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}