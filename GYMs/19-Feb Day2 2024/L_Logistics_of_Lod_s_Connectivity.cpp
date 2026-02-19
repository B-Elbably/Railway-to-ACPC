#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

bool check(int start1, int end1, int start2, int end2) {
    return max(start1, start2) < min(end1, end2);
}

bool can(int start1, int len1, int start2, int len2) {
    if (len1 == 0 || len2 == 0) return false;
    int end1 = (start1 + len1) % 24;
    int end2 = (start2 + len2) % 24;
    if (end1 > start1) {
        if (end2 > start2) 
            return check(start1, end1, start2, end2);
        else 
            return check(start1, end1, start2, 24) || check(start1, end1, 0, end2);
    } else {
        if (end2 > start2) 
            return check(start1, 24, start2, end2) || check(0, end1, start2, end2);
        else 
            return check(start1, 24, start2, 24) || check(start1, 24, 0, end2)
                || check(0, end1, start2, 24) || check(0, end1, 0, end2);
    }
}

void solve() {
    int n, m, e;
    cin >> n >> m >> e;
    vector<int> freq(24, 0);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        freq[a]++;
    }

    int ans = 0;
    for (int start = 0; start < 24; start++) {
        int res = 0;
        for (int i = 0; i < 24; i++) {
            if (can(start, m, i, e)) continue;
            res += freq[i];
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
