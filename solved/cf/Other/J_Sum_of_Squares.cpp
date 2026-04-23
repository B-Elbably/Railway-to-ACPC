#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2")
#define int long long
#define all(i) (i).begin(), (i).end()
#define endl '\n'

const int N = 1e6 + 5;
int ans[N];
void build() {
    fill(ans, ans + N, 1000);
    for (int i = 1; i * i < N; i++) {
        ans[i * i] = 1;
    }
    for (int i = 0; i * i < N; i++) {
        int aa = i * i;
        for (int j = i; j * j < N - aa; j++) {
            int val = aa + j * j;
            ans[val] = min(ans[val], 2LL);
        }
    }
    for (int i = 1; i < N; i++) {
        if (ans[i] > 2) {
            for (int sq = 1; sq * sq <= i; sq++) {
                ans[i] = min(ans[i], 1 + ans[i - sq * sq]);
                if (ans[i] == 3) break;
            } 
        }
    }
}

void solve() {
    int x ,n;
    cin >> x >> n;
    cout << (ans[x] <= n? "YES": "NO") << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    build();
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}

// 28 -> 7
// 9 9 9 1
// 16 9 1 1 1
// 16 4 4 4
// 25 1 1 1
