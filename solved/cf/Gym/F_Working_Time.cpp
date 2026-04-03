#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int calc(string s) {
    string p1 = s.substr(0, s.find(':'));
    string p2 = s.substr(s.find(':') + 1);
    return stoll(p1) * 60 + stoll(p2);
}
void solve() {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        string s, e;
        cin >> s >> e;
        ans += calc(e) - calc(s);
    }
    if (ans < m * 60) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
