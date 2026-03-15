#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll a, b;
    cin >> a >> b;
    ll diff = min(10LL, b - a);
    ll ans = 1;
    ll cur = b % 10;
    for (ll i = 0; i < diff; i++) {
        if (cur == 0) cur = 10;
        ans *= cur;
        cur--;
    }
    cout << ans % 10 << endl;
}
