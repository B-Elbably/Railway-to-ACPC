#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int sum = 0;
    for (int x: a) sum ^= x;
    if (sum == 0) {
        cout << "YES" << endl;
        return;
    }
    int cnt = 0;
    int sum2 = 0;
    for (int x: a) {
        sum2 ^= x;
        if (sum2 == sum) {
            cnt++;
            sum2 = 0;
        }
    }
    cout << (cnt > 1 ? "YES" : "NO") << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
