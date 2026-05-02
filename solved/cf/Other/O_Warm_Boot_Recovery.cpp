#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int zero = 0, one = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) zero++;
        else one++;
    }
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) cnt0++;
        else cnt1++;
        if (cnt0 == zero || cnt1 == one) {
            cout << i + 1 << endl;
            return;
        }
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
