#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int ans = 2;
    int l = -1, r = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] != ((i & 1)? 'a' : 'b')) {
            if (l == -1) l = i;
            r = i;
        }
    }
    if (~l) {
        bool ok1 = 1, ok2 = 1;
        int i = l;
        for (;i <= r; ++i) {
            int idx = r - i + l;
            char si = s[idx], ti = ((i & 1)? 'a' : 'b');
            if (si != ti) ok1 = 0;
            if (si == ti) ok2 = 0;
        }
        ans -= 1 - (ok1 || ok2);
    }else ans--;

    l = -1, r = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] != ((i & 1)? 'b' : 'a')) {
            if (l == -1) l = i;
            r = i;
        }
    }
    if (~l) {
        bool ok1 = 1, ok2 = 1;
        int i = l;
        for (;i <= r; ++i) {
            int idx = r - i + l;
            char si = s[idx], ti = ((i & 1)? 'b' : 'a');
            if (si != ti) ok1 = 0;
            if (si == ti) ok2 = 0;
        }
        ans -= 1 - (ok1 || ok2);
    }else ans--;
    // cout << ans;
    if (ans) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }
    // cout << endl;
    // cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
