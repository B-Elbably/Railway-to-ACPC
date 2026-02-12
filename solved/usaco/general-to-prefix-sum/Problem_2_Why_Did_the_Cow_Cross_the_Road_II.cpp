#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    string s; cin >> s;
    vector<int> first(26, -1), last(26);
    for (int i = 0; i < 52; i++) {
        int c = s[i] - 'A';
        if (first[c] == -1) first[c] = i;
        last[c] = i;
    }

    int ans = -26;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            // fi < fj < li < lj
            if (first[i] > first[j] || last[i] > last[j] ) continue;
            ans += (first[j] < last[i]);
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    solve();
}
