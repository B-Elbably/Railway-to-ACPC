#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int n, m;
string s, t;
vector<int> freq1(26);
vector<int> idices[26];

bool search(int i, int add, vector<int>& freq, string& ans) {
    if (add == m) return true;
    for (int c = 25; c >= 0; --c) {
        if (freq[c] == freq1[c]) continue;
        auto it = upper_bound(all(idices[c]), i);
        if (it == idices[c].end()) continue;
        int candy = *it;
        bool ok = true;
        for (int j = 0; j < 26; ++j) {
            int need = freq1[j] - freq[j] - (j == c) ;
            if (idices[j].end() - upper_bound(all(idices[j]), candy) < need) {
                ok = false;
                break;
            }
        }
        if (ok) {
            freq[c]++;
            ans += (char)('a' + c);
            if (search(candy, add + 1, freq, ans)) return true;
            ans.pop_back();
            freq[c]--;
        }
    }
    return false;
}

void solve() {
    fill(all(freq1), 0);
    for (int i = 0; i < 26; ++i) {
        idices[i].clear();
    }
    cin >> n >> m;
    cin >> s >> t;
    for (auto &x : t) freq1[x - 'a']++;
    for (int i = 0; i < n; ++i) {
        idices[s[i] - 'a'].push_back(i);
    }

    vector<int> freq(26, 0);
    string ans = "";
    if (search(-1, 0, freq, ans)) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}