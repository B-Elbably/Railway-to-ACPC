#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 1e6 + 15;
int Z[N];
void z_function(const string& s) {
    int n = s.length();
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            Z[i] = min(r - i + 1, Z[i - l]);
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]])
            ++Z[i];
        if (i + Z[i] - 1 > r)
            l = i, r = i + Z[i] - 1;
    }
}