#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    set<int> a;
    for (int i = 1; i <= n; i++) a.insert(i);
    int step = 2;
    int start = 2;
    while (!a.empty()) {
        vector<int> to_remove;
        for (int x = start; x <= n; x += step) {
            if (a.count(x)) {
                to_remove.push_back(x);
            }
        }
        int end = *a.rbegin();        
        for (int x : to_remove) {
            cout << x << " ";
            a.erase(x);
        }
        start = (to_remove.back() == end && a.size() > 1) ? *next(a.begin()) : *a.begin();
        step <<= 1;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
    return 0;
}