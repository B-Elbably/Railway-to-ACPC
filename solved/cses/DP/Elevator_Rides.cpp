#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, x;
vector<int> a;
pair<int, int> memo[1 << 20];

pair<int, int> go(int mask) {
    if (mask == 0) return {1, 0};
    auto &ret = memo[mask];
    if (ret.first) return ret;
    ret = {n + 1, 0};
    for (int i = 0; i < n; ++i) {
        if ((mask >> i) & 1) {
            pair<int, int> op1 = go(mask ^ (1 << i));
            pair<int, int> op2;
            if (op1.second + a[i] <= x) {
                op2 = {op1.first, op1.second + a[i]};
            } else {
                op2 = {op1.first + 1, a[i]};
            }
            ret = min(ret, op2);
        }
    }
    return ret;
}

void solve() {
    cin >> n >> x;
    a.resize(n);
    for (auto &i : a) cin >> i;
    cout << go((1 << n) - 1).first << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}