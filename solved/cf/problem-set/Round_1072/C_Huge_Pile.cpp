#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

map<ll, ll> memo;
ll m;
const ll INF = 1e18;

ll dfs(ll n) {
    if (n == m) return 0;
    if (n < m) return INF;
    if (memo.count(n)) return memo[n];
    ll a = n / 2;
    ll b = n - a;
    ll res = INF;
    if (a != n) res = min(res, dfs(a));
    if (b != n) res = min(res, dfs(b));
    if (res == INF) return memo[n] = INF;
    return memo[n] = res + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n >> m;
        memo.clear();

        ll ans = dfs(n);
        if (ans >= INF) cout << "-1\n";
        else cout << ans << "\n";
    }
}
