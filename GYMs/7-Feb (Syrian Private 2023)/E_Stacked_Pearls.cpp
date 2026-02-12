#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'


void solve() {
    int n, q;
    cin >> n >> q;
    map<pair<int, int>, int> a;
    map<int, int> evens, odds;
    while (q--)
    {
        int x, y, val;
        cin >> x >> y >> val;
        if (a.count({--x, --y}) && a[{x, y}] != 0) {
            if ((x + y) & 1) {
                odds[a[{x, y}]]--;
                if (odds[a[{x, y}]] == 0) odds.erase(a[{x, y}]);
            } else {
                evens[a[{x, y}]]--;
                if (evens[a[{x, y}]] == 0) evens.erase(a[{x, y}]);
            }
        }
        a[{x, y}] = val;
        if (val != 0) {
            if ((x + y) & 1)  odds[val]++;
            else evens[val]++;
        }
        if (evens.size() <= 1 && odds.size() <= 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}