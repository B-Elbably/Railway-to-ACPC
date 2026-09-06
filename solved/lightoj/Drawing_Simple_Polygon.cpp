#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
using T = long double;
// using pt = complex<T>;
struct pt{
    int x, y, id;
};

// #define x real()
// #define y imag()
const T EPS = 1e-9;
const T PI = acos((T)-1.0);

T orient(pt a, pt b, pt c) { return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x); }
T dist(pt a, pt b) { 
    return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y); 
}

T cross(pt a, pt b, pt c) { return orient(a, b, c); }


int tc = 0;
void solve() {
    int n; 
    cin >> n;
    vector<pt> p(n);
    int piv = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y; 
        p[i].id = i;
        if (p[i].y < p[piv].y || (p[i].y == p[piv].y && p[i].x < p[piv].x)) piv = i;
    }
    swap(p[0], p[piv]);
    sort(p.begin() + 1, p.end(), [&](pt a, pt b) {
        int c = cross(p[0], a, b);
        return c ? c > 0 : dist(p[0], a) < dist(p[0], b);
    });
    
    int i = n - 1;
    while (i > 0 && cross(p[0], p[i], p[n - 1]) == 0) i--;
    
    cout << "Case " << ++tc << ":\n";
    if (i == 0) {
        cout << "Impossible\n";
        return;
    }
    
    reverse(p.begin() + i + 1, p.end());
    for (int j = 0; j < n; j++) cout << p[j].id << " ";
    cout << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
