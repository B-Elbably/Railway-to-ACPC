#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
int grid[16][16];
int memo[16][1 << 16];
vector<int> valid_masks;

bool is_valid(int mask) {
    return !(mask & (mask << 1));
}

bool are_compatible(int m1, int m2) {
    return !(m1 & m2) && !(m1 & (m2 << 1)) && !(m1 & (m2 >> 1));
}

int col_sum(int col, int mask) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if ((mask >> i) & 1) sum += grid[i][col];
    }
    return sum;
}

int go(int col, int prev_mask) {
    if (col == n) return 0;
    if (memo[col][prev_mask] != -1) return memo[col][prev_mask];

    int res = 0;
    for (int mask : valid_masks) {
        if (are_compatible(mask, prev_mask)) {
            res = max(res, col_sum(col, mask) + go(col + 1, mask));
        }
    }

    return memo[col][prev_mask] = res;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    valid_masks.clear();
    for (int i = 0; i < (1 << n); i++) {
        if (is_valid(i)) valid_masks.push_back(i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            memo[i][j] = -1;
        }
    }

    cout << go(0, 0) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}