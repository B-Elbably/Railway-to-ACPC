#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
map<char, int> mp = {
    {'a', 2}, {'b', 2}, {'c', 2},
    {'d', 3}, {'e', 3}, {'f', 3},
    {'g', 4}, {'h', 4}, {'i', 4},
    {'j', 5}, {'k', 5}, {'l', 5},
    {'m', 6}, {'n', 6}, {'o', 6},
    {'p', 7}, {'q', 7}, {'r', 7}, {'s', 7},
    {'t', 8}, {'u', 8}, {'v', 8},
    {'w', 9}, {'x', 9}, {'y', 9}, {'z', 9}
};

void solve() {
    int n, q;
    cin >> n >> q;
    map<string, int> freq;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        string res(s.size(), ' ');
        for (int j = 0; j < s.size(); j++) {
            res[j] = mp[s[j]] + '0';
        }
        freq[res]++;
    }
    while (q--)
    {
        string s; cin >> s;
        cout << freq[s] << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
