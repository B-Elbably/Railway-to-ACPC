#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, n;
    cin >> x >> n;
    set<int> pos = {0, x};
    multiset<int> gaps = {x};

    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        auto it = pos.upper_bound(p);
        int R = *it;
        int L = *prev(it);

        gaps.erase(gaps.find(R - L));
        gaps.insert(p - L);
        gaps.insert(R - p);
        pos.insert(p);

        cout << *gaps.rbegin() << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}