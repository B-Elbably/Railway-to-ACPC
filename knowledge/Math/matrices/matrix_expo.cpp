#include <vector>
#include <iostream>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAX_LOG = 62; 

struct FastExp {
    int N;
    vector<vector<vector<ll>>> powers;

    FastExp(vector<vector<ll>> A) : N(A.size()) {
        powers.push_back(A);
        for (int i = 1; i < MAX_LOG; i++) {
            powers.push_back(multiply(powers.back(), powers.back()));
        }
    }

    vector<vector<ll>> multiply(const vector<vector<ll>>& A, const vector<vector<ll>>& B) {
        vector<vector<ll>> C(N, vector<ll>(N, 0));
        for (int i = 0; i < N; i++)
            for (int k = 0; k < N; k++)
                for (int j = 0; j < N; j++)
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
        return C;
    }

    vector<ll> query(ll m, vector<ll> v) {
        for (int i = 0; i < MAX_LOG; i++) {
            if ((m >> i) & 1) {
                vector<ll> next_v(N, 0);
                for (int r = 0; r < N; r++)
                    for (int c = 0; c < N; c++)
                        next_v[r] = (next_v[r] + powers[i][r][c] * v[c]) % MOD;
                v = next_v;
            }
        }
        return v;
    }
};

void solve() {
    int N = 2;
    vector<vector<ll>> A = {{1, 1}, {1, 0}};
    FastExp solver(A);

    int q = 1;
    // cin >> q;
    while (q--) {
        ll m;
        cin >> m;
        vector<ll> v = {1, 0}; 
        vector<ll> result = solver.query(m, v);
        
        cout << result[0] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}