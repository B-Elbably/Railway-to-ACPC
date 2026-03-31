#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 5e3 + 5;
int memo[N][N];
int n;
vector<int> one, zero;

int go(int i, int j) {
    if (i == one.size()) return 0;
    if (j == zero.size()) return 1e12;
    int &ret = memo[i][j];
    if (~ret) return ret;
    ret = 1e12;
    ret = min(ret, go(i, j + 1));
    ret = min(ret, go(i + 1, j + 1) + abs(one[i] - zero[j]));
    return ret;
}

void solve() {
    memset(memo, -1, sizeof(memo));
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x) one.push_back(i);
        else zero.push_back(i);
    }
    cout << go(0, 0) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}