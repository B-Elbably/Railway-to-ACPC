#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> P(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        if (!st.empty()) P[i] = st.top();
        st.push(i);
    }

    int ans = n * (n + 1) / 2;
    int H = 0;

    for (int j = 1; j < n; j++) {
        int valid_l = 0;
        if (a[j] > a[j - 1] + 1) {
            valid_l = j;
            H = j;
        } else {
            if (P[j] < H) {
                valid_l = j;
            } else {
                valid_l = j - 1 - P[j];
            }
        }
        ans += valid_l * (n - j);
    }

    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}