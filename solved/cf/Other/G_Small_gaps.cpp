#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int n;
bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void brute() {
    if (is_prime(n)) {
        cout << 1 << endl << n;
        return;
    }
    if (is_prime(n - 2)) {
        cout << 2 << endl << 2 << " " << n - 2;
        return;
    }
    if (is_prime(n - 4)) {
        cout << 3 << endl << 2 << " " << 2 << " " << n - 4;
        return;
    }
    if (is_prime(n - 5)) {
        cout << 3 << endl << 2 << " " << 3 << " " << n - 5;
        return;
    }
    cout << 3 << endl;
    for (int i = 3; i < n; i+= 2) {
        if (!is_prime(i)) continue;
        for (int j = 3; j < n; j+= 2) {
            if (!is_prime(j)) continue;
            int k = n - i - j;
            if (k < 2 || !is_prime(k)) continue;
            cout << i << " " << j << " " << k << endl;
            return;
        }
    }
}

void solve() {
    cin >> n;
    brute();

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
