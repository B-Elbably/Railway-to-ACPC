#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    multiset<int> s;
    int x; cin >> x;
    s.insert(x);
    int n; cin >> n;
    auto it = s.begin();
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        s.insert(a);
        s.insert(b);
        if (a < *it && b < *it) {
            it--;
        } else if (a >= *it && b >= *it) {
            it++;
        }
        cout << *it << endl;
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
