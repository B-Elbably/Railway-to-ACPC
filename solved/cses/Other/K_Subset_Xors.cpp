#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 31;
int basis[N];
vector<int> b;

void insert(int x) {
    for (int i = N - 1; i >= 0; --i) {
        int mask = 1LL << i;
        if (!(x & mask)) continue;
        if (basis[i] == 0) {
            basis[i] = x;
            return;
        }
        insert(x ^ basis[i]);
        return;
    }
}

void reduce() {
    for (int i = 0; i < N; ++i) {
        if (basis[i] == 0) continue;
        for (int j = 0; j < i; ++j) {
            if (basis[i] & (1LL << j)) basis[i] ^= basis[j];
        }
        b.push_back(basis[i]);
    }
}

int kth(int k) {
    int ans = 0;
    for (int i = 0; i < b.size(); ++i) {
        if (k & (1LL << i)) ans ^= b[i];
    }
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
        insert(x);
    }
    reduce();
    int dup = n - b.size();
    for (int i = 0; i < k; ++i) {
        int idx = i >> dup;
        cout << kth(idx) << " ";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}