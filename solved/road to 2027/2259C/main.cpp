#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int one= 0, minus = 0;
    for (auto &x : a) {
        cin >> x;
        if (x == 1) one++;
        else if (x == -1) minus++;
    }
    int ok1 = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == -1) {
            if (!ok1) {
                ok1 = 1;
                a[i] = 1;
                minus--;
            }else {
                if (one == 0 && minus == 1) {
                    a[i] = 1;
                    minus--;
                }else {
                    a[i] = 0;
                    minus--;
                }
            }
        }else if (a[i] == 1) {
            one--;
            ok1 = 1;
        }
    }
    for (int i: a) cout << i << " ";
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
