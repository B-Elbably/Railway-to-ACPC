#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
vector<int> pref;
string s;

bool check(int i) {
    bool ok = (s[i] == 'L' && s[i] != s[i + 1] && (pref[i] > 0 ));
    // if (ok) cout << i << " " << pref[i] << "\n";
    return ok;
}

void solve() {
    int n, q; 
    cin >> n >> q;
    vector<int> a(n + 1);
    pref.assign(n + 2, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        int l = min(i, a[i]);
        int r = max(i, a[i]);
        pref[l]++; pref[r]--;
    }
    for (int i = 1; i <= n; ++i) {
        pref[i] += pref[i - 1];
    }
    cin >> s;
    s = ' ' + s; 
    int bad = 0;
    for (int i = 1; i < n; ++i) {
        if (check(i)) bad++;
    }
    while(q--) {
        int idx; cin >> idx; 
        if (idx + 1 < n && check(idx)) bad--;
        if (idx && check(idx - 1)) bad--;
        s[idx] = (s[idx] == 'R' ? 'L' : 'R');
        if (idx + 1 < n && check(idx)) bad++;
        if (idx && check(idx - 1)) bad++;
        cout << (bad == 0 ? "YES" : "NO") << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
