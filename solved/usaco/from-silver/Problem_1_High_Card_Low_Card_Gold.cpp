#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> elsie(n);
    vector<int> used(2*n+1);
    for (auto &x : elsie) {
        cin >> x;
        used[x] = 1;
    }

    multiset<int> bessie;
    for (int i = 1; i <= 2*n; ++i)
        if (!used[i]) bessie.insert(i);

    int ans = 0;
    for (int i = 0; i < n/2; ++i) {
        auto it = bessie.upper_bound(elsie[i]);
        if (it == bessie.end()) {
            bessie.erase(bessie.begin());
        } else {
            ans++;
            bessie.erase(it);
        }
    }

    for (int i = n/2; i < n; ++i) {
        auto it = bessie.lower_bound(elsie[i]);
        if (it == bessie.begin()) {
            auto last = prev(bessie.end());
            bessie.erase(last);
        } else {
            --it;
            ans++;
            bessie.erase(it);
        }
    }

    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("cardgame.in", "r", stdin);
    // freopen("cardgame.out", "w", stdout);

    solve();
}
