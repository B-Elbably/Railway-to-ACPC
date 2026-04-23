#include <bits/stdc++.h>
using namespace std;

int ask(const vector<int>& v) {
    if (v.empty()) return 0;
    cout << "? " << v.size();
    for (int x : v) cout << " " << x;
    cout << endl;
    int res; cin >> res;
    if (res == -1) exit(0);
    return res;
}

void solve() {
    int n; cin >> n;
    n = 2 * n + 1;
    int l = 1, r = n, ans3 = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        vector<int> q;
        for (int i = 1; i <= mid; ++i) q.push_back(i);
        if ((mid - ask(q)) % 2) {
            ans3 = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    l = 1, r = ans3;
    int ans1 = 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        vector<int> q;
        for (int i = mid; i <= ans3; ++i) q.push_back(i);
        if ((q.size() - ask(q)) % 2) {
            ans1 = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    l = ans1, r = ans3 - 1;
    int ans2 = ans1;
    while (l <= r) {
        int mid = (l + r) / 2;
        vector<int> q;
        for (int i = ans1; i <= mid; ++i) q.push_back(i);
        q.push_back(ans3);
        if ((q.size() - ask(q)) % 2) {
            ans2 = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << "! " << ans1 << " " << ans2 << " " << ans3 << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}