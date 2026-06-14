#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 5e5 + 5;
int spf[N];
void build() {
    iota(spf, spf + N, 0);
    for (int i = 2; i * i < N; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < N; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}
gp_hash_table<int, int> freq;
int ans = 1;
const int MOD = 1e9 + 7;
void factorize(int n) {
    int sum = 1;
    while (n > 1) {
        int p = spf[n];
        int c = 0;
        while (n % p == 0) {
            n /= p;
            c++;
        }
        // sum += c;
        freq[p] += c;
    }
    // ans *= sum;
    // ans %= MOD;
}

vector<vector<int>> candy;
void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    for (int i: a) factorize(i);
    int ans = 1;
    for (auto [k, v]: freq) {
        ans *= (v + 1);
        ans %= MOD;
    } 
    cout << ans << endl;
    freq.clear();
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
