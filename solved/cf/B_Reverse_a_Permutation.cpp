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
    int i = 0, j = 0, target = n;
    for (; i < n; ++i){
        if (a[i] == target) {
            target--;
        } else {
            for (j = i; j < n; ++j) {
                if (a[j] == target) {
                    break;
                }
            }
            break;
        }
    }
    if (i < j) {
        reverse(a.begin() + i, a.begin() + j + 1);
    }
    for (auto x : a) cout << x << ' ';
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
