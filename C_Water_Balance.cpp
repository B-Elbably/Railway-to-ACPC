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
    vector<pair<double, int>> st;

    for (int i = 0; i < n; i++) {
        double sum = a[i];
        int cnt = 1;
        while (!st.empty() && st.back().first >= sum / cnt) {
            sum += st.back().first * st.back().second;
            cnt += st.back().second;
            st.pop_back();
        }
        st.push_back({sum / cnt, cnt});
    }

    cout << fixed << setprecision(10);
    for (auto& p : st) {
        for (int i = 0; i < p.second; i++) {
            cout << p.first << "\n";
        }
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
