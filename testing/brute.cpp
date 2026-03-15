#include <bits/stdc++.h>
using namespace std;

string M;
int N;
long long MOD = 1e9 + 7;

long long dfs(int l, int r, int shika, int koshi) {
    if (l > r) return 1; // all cookies eaten

    long long res = 0;

    // take from left
    if (M[l] == '1') // deer cookie → Shikanoko
        res += dfs(l + 1, r, shika + 1, koshi);
    else if (M[l] == '0' && shika >= koshi + 1) // human cookie → Koshi
        res += dfs(l + 1, r, shika, koshi + 1);

    // take from right
    if (M[r] == '1')
        res += dfs(l, r - 1, shika + 1, koshi);
    else if (M[r] == '0' && shika >= koshi + 1)
        res += dfs(l, r - 1, shika, koshi + 1);

    return res % MOD;
}

int main() {
    cin >> N >> M;
    cout << dfs(0, N - 1, 0, 0) << endl;
}