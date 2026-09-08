#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int one = 0, two = 0, three = 0;
    for (auto &x : a) {
        cin >> x;
        if (x == 1) one++;
        else if (x == 2) two++;
        else three++;
    }
    if (one) {
        cout << -1 << endl;
        return;
    }
    if (n == 1){
        cout << a[0] << endl;
        return;
    }
    if (n == 2 && two && three) {
        cout << a[0] << " " << a[1] << endl;
        return;
    }
    if (n == 3 && two == 2 && three == 1) {
        cout << 2 << " " << 3 << " " << 2 << endl;
        return;
    }
    cout << -1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
