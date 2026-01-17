#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
// Beatrice Belinda Bella Bessie Betsy Blue Buttercup Sue 
void solve() {
    vector<string> cows = {
        "Beatrice", "Belinda", "Bella", "Bessie", 
        "Betsy", "Blue", "Buttercup", "Sue"
    };
    vector<int> indices = {0, 1, 2, 3, 4, 5, 6, 7};

    int n;
    cin >> n;
    vector<pair<int, int>> require(n);
    for (auto &x : require){
        string name;
        cin >> name;
        x.first = find(all(cows), name) - cows.begin();
        for (int i = 0; i < 5; i++) cin >> name;
        x.second = find(all(cows), name) - cows.begin();
    }
    vector<int> ans = {7, 6, 5, 4, 3, 2, 1, 0};
    do {
        bool ok = true;
        for (auto [a, b] : require) {
            int pos_a = find(all(indices), a) - indices.begin();
            int pos_b = find(all(indices), b) - indices.begin();
            if (abs(pos_a - pos_b) > 1) {
                ok = false;
                break;
            }
        }
        if (ok) ans = min(ans, indices);
    }while (next_permutation(all(indices)));

    for (auto x : ans) cout << cows[x] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
