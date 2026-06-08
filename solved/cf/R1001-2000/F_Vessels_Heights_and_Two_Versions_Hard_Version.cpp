#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define x first
#define y second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int mx = max_element(all(a)) - a.begin() + 1;
    vector<int> seq(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        seq[i] = a[(mx + i) % n];
    }
    vector<pair<int, int>> st;
    int sum = 0;
    vector<int> ans(n);
    for (int i = n - 2; i >= 0; --i) {
        int cnt = 1;
        while (!st.empty() && st.back().first <= seq[i]) {
            sum -= st.back().x * st.back().y;
            cnt += st.back().y;
            st.pop_back();
        }
        st.push_back({seq[i], cnt});
        sum += seq[i] * cnt;
        ans[(mx + i) % n] = sum;
    }

    while (!st.empty()) st.pop_back();
    sum = 0;
    for (int i = 0; i < n - 1; ++i) {
        int cnt = 1;
        while (!st.empty() && st.back().first <= seq[i]) {
            sum -= st.back().x * st.back().y;
            cnt += st.back().y;
            st.pop_back();
        }
        st.push_back({seq[i], cnt});
        sum += seq[i] * cnt;
        ans[(mx + i + 1) % n] += sum;
    }
    for (int i = 0; i < n; ++i) cout << ans[i] << " ";
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
