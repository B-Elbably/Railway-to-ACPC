#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    string s;
    cin >> s;
    int cnt = 1;
    char last = s[0];
    vector<int> ans;
    map<int, int> mp;
    for (int i = 1; i < s.size(); ++i) {
        mp[last - 'a']++;
        if (last == s[i]) cnt++;
        else {
            ans.push_back(cnt);
            cnt = 1;
        }
        last = s[i];
    }
    mp[last - 'a']++;
    ans.push_back(cnt);
    int res = 1;
    int res2 = 0;
    for (auto [k, v]: mp) res2 = max(res2, v);
    for (int i: ans){
        res *= i;
    }  
    cout << max(res, res2);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}