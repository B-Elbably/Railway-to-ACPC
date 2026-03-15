#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int N = i * i;
        int total = N * (N - 1) / 2;
        int attack = 4 * (i - 1) * (i - 2);
        cout << total - attack << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}

/*
0    ->  0    (1)
6    ->  3    (4)
28   ->  14   (9)
96   ->  48   (16)
252  ->  126  (25)
550  ->  275  (36)
1056 ->  528  (49)
1848 ->  924  (64)
*/


// pascal's triangle
/*
1  ->  1

4  ->  1 3 3 1

9  ->  1 8 28 56 70 56 28 8 1

16 -> 1 15 105 455 1365 3003 5005 6435 6435 5005 3003 1365 455 105 15 1
*/