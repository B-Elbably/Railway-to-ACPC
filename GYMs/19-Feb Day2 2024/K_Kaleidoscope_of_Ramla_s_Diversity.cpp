#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int n, q;
vector<int> a;
const int MOD = 998244353;
vector<vector<int>> Matrix;

void brute() {
    vector<int> b = a;
    vector<int> c(n); 

    for (int i = 0; i < q; i++) {
        int sum = accumulate(b.begin(), b.end(), 0LL);
        for (int j = 0; j < n; j++) {
            c[j] = sum - 2 * b[j];
        }
        b = c;
        cout << "After query " << i + 1 << ": " << sum << " || ";
        for (int x : b) cout << x << " "; cout << endl;
    }
}

int modexp(int x, int n) {
    x %= MOD;
    int res = 1;
    while (n > 0) {
        if (n & 1) res = (res * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;
    }
    return res;
}

vector<vector<int>> MulMat(const vector<vector<int>> &a, const vector<vector<int>> &b) {
    int n = a.size(), k = b[0].size();
    vector<vector<int>> ans(n, vector<int>(k, 0));
    for(int i=0;i<n;i++)
        for(int j=0;j<k;j++)
            for(int l=0;l<a[0].size();l++)
                ans[i][j] = (ans[i][j] + a[i][l]*b[l][j]%MOD) % MOD;
    return ans;
}

vector<vector<int>> MatPower(int p) {
    int sz = Matrix.size();
    vector<vector<int>> ans(sz, vector<int>(sz,0));
    for(int i=0;i<sz;i++) ans[i][i] = 1;
    vector<vector<int>> base = Matrix;
    while(p) {
        if(p & 1) ans = MulMat(ans, base);
        base = MulMat(base, base);
        p >>= 1;
    }
    return ans;
}


void solve() {
    cin >> n >> q;
    a.resize(n);
    int sum = 0;
    for (auto &x : a) {
        cin >> x;
        sum = (sum + x) % MOD;
    }
    // brute();
    Matrix = {{-2 + MOD, 1},{0, (n - 2) % MOD}};
    Matrix = MatPower(q);

    sum = (sum * Matrix[0][1]) % MOD;

    for(int i = 0;i < n;i++) {
        // a[i] =
        a[i] = (a[i] * Matrix[0][0] % MOD + sum) % MOD;
        cout << a[i] << "\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}

// s[i] = sum(a) - 2 * a[i]
//                                                 
// sum  16 -> 48 -> 144 -> 432 -> 1296
// 0-th  1 -> 14 ->  20 -> 104 -> 224
// s[]

// i-th = S[i - 1] - 2 * a[i - 1]
// S[i] = sum * (n - 2) ^ i;