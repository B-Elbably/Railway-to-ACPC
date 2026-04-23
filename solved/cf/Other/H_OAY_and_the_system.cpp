#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
map<string, int> mp;
void solve() {
    string s; cin >> s;
    if (mp.count(s)) {
        cout << s << mp[s] << endl;
        mp[s]++;
    }else {
        cout << "OK\n";
        mp[s] = 1;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
