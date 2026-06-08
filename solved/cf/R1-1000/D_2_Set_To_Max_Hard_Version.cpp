#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int N = 250005;
const int LOG = 20;

int mx[LOG][N];
int mn[LOG][N];
int lg[N];

void precompute_logs() {
    lg[1] = 0;
    for (int i = 2; i < N; i++) {
        lg[i] = lg[i / 2] + 1;
    }
}

void build(int n, const vector<int>& a, const vector<int>& b) {
    for (int i = 0; i < n; i++) {
        mx[0][i] = a[i];
        mn[0][i] = b[i];
    }
    for (int j = 1; j < LOG; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            mx[j][i] = max(mx[j - 1][i], mx[j - 1][i + (1 << (j - 1))]);
            mn[j][i] = min(mn[j - 1][i], mn[j - 1][i + (1 << (j - 1))]);
        }
    }
}

int get_mx(int L, int R) {
    int j = lg[R - L + 1];
    return max(mx[j][L], mx[j][R - (1 << j) + 1]);
}

int get_mn(int L, int R) {
    int j = lg[R - L + 1];
    return min(mn[j][L], mn[j][R - (1 << j) + 1]);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<vector<int>> pos(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    build(n, a, b);
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            cout << "NO" << endl;
            return;
        }
        if (a[i] == b[i]) continue;
        int target = b[i];
        const auto& v = pos[target];
        auto it = lower_bound(v.begin(), v.end(), i);
        bool ok = false;
        if (it != v.end()) {
            if (get_mx(i, *it) == target && 
                get_mn(i, *it) == target) {
                ok = true;
            }
        }
        if (!ok && it != v.begin()) {
            if (get_mx(*prev(it), i) == target &&
                get_mn(*prev(it), i) == target) {
                ok = true;
            }
        }
        if (!ok) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute_logs();

    int t = 1;
    cin >> t; 
    while (t--) {
        solve();
    }
    return 0;
}