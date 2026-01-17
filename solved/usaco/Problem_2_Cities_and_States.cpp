#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
string city, state;
void solve() {
    int n;
    cin >> n;
    map<pair<string,string>, int> mp;
    vector<pair<string,string>> cities(n);
    for (int i = 0; i < n; ++i) {
        cin >> city >> state;
        cities[i] = {city.substr(0, 2), state};
        mp[cities[i]]++;
    }

    int ans = 0;
    for (auto &[city, state] : cities) {
        if (city == state) continue;
        ans += mp[{state, city}]; 
    }
    cout << ans / 2 << endl; 
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);
    solve();
}
