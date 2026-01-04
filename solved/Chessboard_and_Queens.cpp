#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> a(8, vector<char>(8));
int ans = 0;

bool ok(int r, int c) {
    for (int i = 0; i < r; i++)
        if (a[i][c] == 'Q') return false;

    for (int i = r-1, j = c-1; i >= 0 && j >= 0; i--, j--)
        if (a[i][j] == 'Q') return false;

    for (int i = r-1, j = c+1; i >= 0 && j < 8; i--, j++)
        if (a[i][j] == 'Q') return false;

    return true;
}

void go(int r) {
    if (r == 8) {
        ans++;
        return;
    }
    for (int c = 0; c < 8; c++) {
        if (a[r][c] == '*' || !ok(r, c)) continue;
        a[r][c] = 'Q';
        go(r + 1);
        a[r][c] = '.';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (auto &x : a)
        for (auto &y : x)
            cin >> y;

    go(0);
    cout << ans;
}
