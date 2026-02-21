#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int suf = 0, power = 1, ans = 0;
    map<int, int> count;
    count[0] = 1;
    for (int i = n - 1; i >= 0; --i) {
        suf = (suf + (s[i] - '0') * power) % 2019;
        ans += count[suf]++;
        power = (power * 10) % 2019;
    } 
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
