#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 1e5 + 200;
const int MOD = 1e9 + 7;
int memo[N];


void solve() {
    int n; cin >> n;
    string s;
    cin >> s;
    // vector<int> a(n);
    // for (auto &x : a) cin >> x;
    // memo[s[i]][0] = 0
    for (int i = 0; i < 26; ++i) memo[i + 97] = 1;
    for (int i = 0; i < s.size(); i++) {
        memo[s[i] - 'a' + 97] = 0;
    }
    for (int i = 97; i <= n; i++) {
        if (memo[i] == 0) continue;
        for (int j = 97; j < 123; j++) {
            memo[i + j] += memo[i];
            memo[i + j] %= MOD;
        }
    }
    cout << memo[n] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
