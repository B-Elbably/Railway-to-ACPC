#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<char> s(n);
    for (auto &x : s) cin >> x;

    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1' && l == -1) l = i;
        if (s[i] == '0') r = i;
    }

    if (l == -1 || r == -1 || l > r) {
        cout << "Bob\n";
        return;
    }

    vector<int> ans;

    for (int i = l; i <= r; i++) {
        if (s[i] == '1'){
            ans.push_back(i + 1);
            s[i] = '0';
        }
    }
    int nn = ans[ans.size() - 1];
    for (int i = nn; i <= r; i++) {
        if (s[i] == '0'){
            ans.push_back(i + 1);
            s[i] = '1';
        }
    }

    l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1' && l == -1) l = i;
        if (s[i] == '0') r = i;
    }

    vector<char> t = s;
    sort(s.begin(), s.end());
    if (s != t) {
        cout << "Bob\n";
        return;
    }

    cout << "Alice\n";
    cout << ans.size() << endl;
    for (int x : ans) cout << x << ' ';
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
