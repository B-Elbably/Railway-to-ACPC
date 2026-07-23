#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 2e5 + 5;
map<int, vector<int>> mp;

void pre() {
    for (int i = 1; i < N; ++i) {
        for (int g = 1; g * g <= i; ++g) {
            if (i % g) continue;
            {            
                int aj = (i ^ g);
                if (aj && __gcd(i, aj) == g && aj >= i) {
                    mp[i].push_back(aj);
                    // cout << i << " " << aj << " " << g << endl;
                }
            }
            if (g * g == i) continue;
            {
                int xg = i / g;
                if (xg != g) {
                    int aj = (i ^ xg);
                    if (aj && __gcd(i, aj) == xg && aj >= i) {
                        mp[i].push_back(aj);
                        // cout << i << " " << aj << " " << xg << endl;
                    }
                }
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> freq;
    for (auto &x : a) cin >> x, freq[x]++;
    sort(all(a));
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        freq[a[i]]--;
        for (int x: mp[a[i]]) ans += freq[x];
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pre();
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
