#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = s;
    map<char, int> mp, vis;
    for (int i = 0; i < n; i++) {
        mp[s[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        if (vis[s[i]] || s[i] == 'a') continue;
        for (int j = s[i] - 'a' - 1; j >= 0; j--) {
            char now = j + 'a';
            if (mp[now] > i) {
                cout << "YES" << endl;
                cout << i + 1 << " " << mp[now] + 1 << endl;
                return;
            }
        }
        vis[s[i]] = 1;
    }
    cout << "NO";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
