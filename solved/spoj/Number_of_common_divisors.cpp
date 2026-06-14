#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
int num_divisors[N];

void precompute() {
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            num_divisors[j]++;
        }
    }
}

void solve() {
    int a, b;
    cin >> a >> b;
    cout << num_divisors[__gcd(a, b)] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}