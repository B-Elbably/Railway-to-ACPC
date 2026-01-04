#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, k, d1, d2;

bool ok(ll a, ll b, ll c){
    if (a < 0 || b < 0 || c < 0) return false;
    ll mx = max({a, b, c});
    ll rem = n - k - (mx - a) - (mx - b) - (mx - c);
    return rem >= 0 && rem % 3 == 0;
}

bool solve(){
    cin >> n >> k >> d1 >> d2;
    if (n % 3) return false;

    for (ll s1 : {1LL, -1LL})
        for (ll s2 : {1LL, -1LL}) {
            ll a = 2 * s1 * d1 + s2 * d2 + k;
            if (a % 3) continue;
            a /= 3;
            ll b = a - s1 * d1;
            ll c = a - s1 * d1 - s2 * d2;
            if (ok(a, b, c)) return true;
        }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        cout << (solve() ? "yes\n" : "no\n");
}
