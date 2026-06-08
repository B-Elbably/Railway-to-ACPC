#include <bits/stdc++.h>
using namespace std;

int n, a, b, c;
map<int,int> memo;
const int INF = 1e9;

int dp(int x) {
    if (x == 0) return 0;
    if (x < 0) return -INF;
    int &ret = memo[x];
    if (ret != 0) return ret;
    ret = 1 + max({dp(x - a), dp(x - b), dp(x - c)});
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> a >> b >> c;
    cout << dp(n) << "\n";
    return 0;
}
