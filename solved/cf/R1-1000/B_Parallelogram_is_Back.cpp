#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

struct Point {
    int x, y;
};

void solve() {
    Point a, b, c;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    cout << 3 << endl;
    cout << a.x + b.x - c.x << " " << a.y + b.y - c.y << endl;
    cout << a.x + c.x - b.x << " " << a.y + c.y - b.y << endl;
    cout << b.x + c.x - a.x << " " << b.y + c.y - a.y << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}