#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 1e6 + 5;
int freq[N], f[N], g[N], ans[N], phi[N];

int n;
const int MOD = 1e9 + 7;

void pre() {
    for (int i = 0; i < N; i++) phi[i] = i;
    for (int i = 2; i < N; i++)
        if (phi[i] == i)
            for (int j = i; j < N; j += i)
                phi[j] -= phi[j] / i;

    for (int i = 1; i < N; i++)
        for (int j = 2; i * j < N; j++)
            ans[i * j] += 1LL * i * phi[j];

    for (int i = 2; i < N; i++)
        ans[i] += ans[i - 1];
}


void solve() {
    if (!n) return;
    cout << ans[n] << endl;
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pre();
    int t = 1;
    // cin >> t; 
    while (cin >> n) solve();
    return 0;
}
