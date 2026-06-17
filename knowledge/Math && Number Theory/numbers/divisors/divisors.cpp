#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

// Returns sum of divisor counts (d(1) + d(2) + ... + d(n)) in O(sqrt(n))
// d(n) = number of divisors of n
// n <= 1e12
int sum_divisors_count(int n) {
    int count = 0;
    for (int l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l);
        count += (r - l + 1) * (n / l);
    }
    return count;
}

// Returns sum of all divisors (sigma(1) + sigma(2) + ... + sigma(n)) in O(sqrt(n))
// sigma(n) = sum of divisors of n
// n <= 1e12
int sum_of_all_divisors(int n) {
    int total = 0;
    for (int l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l);
        // sum[l..r] = (l+r)*(r-l+1)/2
        int range_sum = (l + r) * (r - l + 1) / 2;
        total += (n / l) * range_sum;
    }
    return total;
}

// sum of divisors of n in O(sqrt(n))
// n <= 1e12
int get_divisor_sum(int n) {
    int sum = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int e = 1;
            int res = 1;
            while (n % i == 0) {
                e *= i;
                res += e;
                n /= i;
            }
            sum *= res;
        }
    }
    if (n > 1) {
        sum *= (n + 1);
    }
    return sum;
}

void solve() {
    int n;
    cin >> n;
    // cout << sum_divisors_count(n) << endl;
    // cout << sum_of_all_divisors(n) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}