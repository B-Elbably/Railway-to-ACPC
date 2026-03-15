#include <bits/stdc++.h>
using namespace std;

#define int long long

string query(int x) {
    cout << "? " << x << endl;
    string res;
    if (!(cin >> res)) exit(0);
    return res;
}

void solve() {
    string color1 = query(0);
    string color2 = (color1 == "W") ? "B" : "W";
    int idx1 = 0, step = 1;
    while (true) {
        if (query(idx1 + step) == color2) break;
        idx1 += step;
        step *= 2;
    }
    int l = 0, r = step, ans = step;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (query(idx1 + mid) == color2) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    int R = idx1 + ans;
    int idx2 = 0; 
    step = 1;
    while (true) {
        if (query(idx2 - step) == color2) break;
        idx2 -= step;
        step *= 2;
    }
    l = 0; 
    r = step;
    ans = step;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (query(idx2 - mid) == color2) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    int L = idx2 - ans;

    cout << "! " << R - L - 1 << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}