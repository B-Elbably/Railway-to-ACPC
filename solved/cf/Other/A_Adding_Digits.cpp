#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int fast_pow(int a, int b, int mod) {
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    string a;
    cin >> a;
    int b, n;
    cin >> b >> n;
    n += a.size();
    int mod = 0;
    for (int i = 0; i < a.size(); i++) {
        int num = a[i] - '0';
        mod += (num % b * fast_pow(10, n - 1, b)) % b;
        n--;
    }
    cout << mod % b << endl;
    
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
