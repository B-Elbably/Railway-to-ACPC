#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 31;
int basis[N];
int ans = 0;
void insert(int x) {
    for (int i = N - 1; i >= 0; --i) {
        int mask = 1LL << i;
        if (!(x & mask)) continue;
        if (basis[i] == 0) {
            basis[i] = x;
            ans++;
            return;
        }
        insert(x ^ basis[i]);
        return;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x, insert(x);
    cout << (1LL << ans )<< endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
