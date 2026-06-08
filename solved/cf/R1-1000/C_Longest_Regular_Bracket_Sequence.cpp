#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    stack<int> st;
    st.push(-1);
    int sum = 0;
    int ans = 0, cnt = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (st.empty()) {
                st.push(i);
            } else {
                int len = i - st.top();
                if (len > ans) {
                    ans = len;
                    cnt = 1;
                } else if (len == ans) {
                    cnt++;
                }
            }
        }
    }
    cout << ans << " " << cnt << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
