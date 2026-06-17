#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int MOD = 1e9 + 7;

// FIXED: Using a flat flat structure instead of vectors eliminates heap allocations
struct Matrix {
    int a00, a01;
    int a10, a11;

    Matrix() : a00(0), a01(0), a10(0), a11(0) {}
    Matrix(int m00, int m01, int m10, int m11) : a00(m00), a01(m01), a10(m10), a11(m11) {}

    static Matrix identity() {
        return Matrix(1, 0, 0, 1);
    }

    // FIXED: Loop unrolling and direct scalar calculations
    Matrix operator*(const Matrix& B) const {
        return Matrix(
            (a00 * B.a00 + a01 * B.a10) % MOD,
            (a00 * B.a01 + a01 * B.a11) % MOD,
            (a10 * B.a00 + a11 * B.a10) % MOD,
            (a10 * B.a01 + a11 * B.a11) % MOD
        );
    }

    static Matrix power(Matrix base, int exp) {
        Matrix result = identity();
        while (exp > 0) {
            if (exp & 1) result = result * base;
            base = base * base;
            exp >>= 1;
        }
        return result;
    }
};

struct Node {
    int f0, f1;
    Matrix P = Matrix::identity();
    Node(int k = -1) {
        if (k == -1) {
            f0 = 0;
            f1 = 0;
            return;
        }
        Matrix A(1, 1, 1, 0);
        Matrix res = Matrix::power(A, k);
        // Multiplying by base column vector [1, 0]^T directly maps to column 0 of res
        f0 = res.a00;
        f1 = res.a10;
    }
};

class SegmentTree {
private:
    int size;
    vector<Node> seg;
    Node merge(const Node &a, const Node &b) {
        Node res;
        res.f0 = a.f0 + b.f0;
        if (res.f0 >= MOD) res.f0 -= MOD; // FIXED: Branching subtraction is faster than % operator
        res.f1 = a.f1 + b.f1;
        if (res.f1 >= MOD) res.f1 -= MOD;
        return res;
    }   
    void apply(int x, const Matrix& P) {
        int nf0 = (P.a00 * seg[x].f0 + P.a01 * seg[x].f1) % MOD;
        int nf1 = (P.a10 * seg[x].f0 + P.a11 * seg[x].f1) % MOD;
        seg[x].f0 = nf0;
        seg[x].f1 = nf1;
        seg[x].P = P * seg[x].P;  
    }

    void push(int x, int lx, int rx) {
        if (rx - lx == 1) return;
        if (seg[x].P.a00 == 1 && seg[x].P.a01 == 0 && 
            seg[x].P.a10 == 0 && seg[x].P.a11 == 1) return;
        apply(2 * x + 1, seg[x].P);  
        apply(2 * x + 2, seg[x].P);
        seg[x].P = Matrix::identity();
    }

    void build(const vector<long long> &v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)v.size())
                seg[x] = Node(v[lx]);
            return;
        }

        int mid = (lx + rx) >> 1;
        build(v, 2 * x + 1, lx, mid);
        build(v, 2 * x + 2, mid, rx);
        seg[x] = merge(seg[2 * x + 1], seg[2 * x + 2]);
    }

    void update(int x, int lx, int rx, int l, int r, const Matrix& P) {
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            apply(x, P);
            return;
        }

        push(x, lx, rx);
        int mid = (lx + rx) >> 1;
        update(2 * x + 1, lx, mid, l, r, P);
        update(2 * x + 2, mid, rx, l, r, P);
        seg[x] = merge(seg[2 * x + 1], seg[2 * x + 2]);
    }

    Node query(int x, int lx, int rx, int l, int r) {
        if (lx >= r || rx <= l) return Node();
        if (lx >= l && rx <= r) return seg[x];

        push(x, lx, rx);
        int mid = (lx + rx) >> 1;
        return merge(
            query(2 * x + 1, lx, mid, l, r),
            query(2 * x + 2, mid, rx, l, r)
        );
    }

public:
    SegmentTree(const vector<long long> &v) {
        size = 1;
        while (size < (int)v.size()) size <<= 1;
        seg.assign(2 * size, Node());
        build(v, 0, 0, size);
    }

    void update(int l, int r, long long v) {
        Matrix A(1, 1, 1, 0);
        Matrix P = Matrix::power(A, v);
        update(0, 0, size, l, r, P);
    }

    long long query(int l, int r) {
        return query(0, 0, size, l, r).f0;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x, x--;
    SegmentTree seg(a);

    while (q--) {
        int type;   
        cin >> type;
        if (type == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            seg.update(--l, r, v);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << seg.query(--l, r) << "\n";
        }
    }
}

int32_t main() {
    // Fast IO
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
    return 0;
}