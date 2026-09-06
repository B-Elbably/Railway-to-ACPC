#include <bits/stdc++.h>
using namespace std;

const int N = 10000005;
int two[N];

void pre() {
    for (int i = 0; i * i < N; i++) {
        for (int j = i; i * i + j * j < N; j++) {
            two[i * i + j * j] = i + 1;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    for (int a = 0; a * a <= n; a++) {
        for (int b = a; a * a + b * b <= n; b++) {
            int rem = n - a * a - b * b;
            if (two[rem]) {
                int c = two[rem] - 1;
                int d = sqrt(rem - c * c);
                cout << a << " " << b << " " << c << " " << d << '\n';
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pre();
    int t;
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}