#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

bool check(int ai, int bi, int i, int aj, int bj, int j) {
    int res = 0;
    if (((ai - aj) <= (i - j)) && ((i - j) <= (bi - bj))) res++;
    if (((aj - ai) <= (j - i)) && ((j - i) <= (bj - bi))) res+= 2;
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n), b(n);
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        a[i - 1] = {x, y};
        b[i - 1] = {x - i, i - y};
    }
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = i + 1; j <= n; ++j) {
    //         int res = check(a[i - 1].first,a[i - 1].second, i, a[j - 1].first,a[j - 1].second, j );
    //         if (!res) continue;
    //         cout << i << " " << j << " " << res << "\n";
    //         cout << a[i - 1].first - i << " " << a[i - 1].second - i << " <-> ";
    //         cout << a[j - 1].first - j << " " << a[j - 1].second - j << "\n====\n";
    //     }
    // }
    sort(all(b));
    // for (auto [x, y]: b) cout << x << " " << y << "\n";
    // int mn = 2e9 + 7, mx = -2e9 - 7;
    // for (int i = 0; i < n; ++i) {
    //     cout << a[i].first << " " << a[i].second << endl;
    // }
    int ans = 0;
    stack<int> st;
    // int l = b[0].first, r = -2e9 ;
    for (int i = 0; i < n; ++i) {
        // if (b[i].second < b[i].first) {
        //     // ans++;
        //     continue;
        // }
        if (st.empty() || st.top() < -b[i].second) {
            // ans++;
            // r = b[i].second;
            st.push(-b[i].second);
        } else {
            int mx = st.top();
            while (!st.empty() && st.top() >= -b[i].second) {
                st.pop();
            }
            // l = min(l, b[i].first);
            // r = max(r, b[i].second);
            st.push(mx);
        }
    }
    cout << st.size();
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
