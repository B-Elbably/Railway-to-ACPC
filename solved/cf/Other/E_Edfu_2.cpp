#include <bits/stdc++.h>

using namespace std;
#define ul unsigned long long
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define endl '\n'

const ul mod = 1e9 + 7;

ul add(ul a, ul b) {
    return (a + b) % mod;
}

ul sub(ul a, ul b) {
    return (a - b + mod) % mod;
}

ul mul(ul a, ul b) {
    return (a * b) % mod;
}

ul fpow(ul a, ul b) {
    if (!b) return 1;
    ul x = fpow(a, b >> 1);
    x = mul(x, x);
    if (b & 1) x = mul(x, a);
    return x;
}

ul divide(ul a, ul b) {
    return mul(a, fpow(b, mod - 2));
}

const ul N = 1e6 + 5;
vector<ul> spf(N), fact(N), inv(N), invFact(N);

void sieve() {
    spf[1] = 1;
    for (ul i = 2; i < N; i++) {
        if (spf[i] == 0) {
            for (ul j = i; j < N; j += i) {
                if (spf[j] == 0)
                    spf[j] = i;
            }
        }
    }
    fact[1] = 1;
    fact[0] = 1;
    for (ul i=2; i<N; i++) {
        fact[i] = mul(i, fact[i-1]);
    }
    inv[1] = 1;
    for (ul i = 2; i < N; i++) {
        inv[i] = mul(mod - mod / i, inv[mod % i]);
    }
    invFact[0] = 1;
    invFact[1] = 1;
    for (ul i = 2; i < N; i++) {
        invFact[i] = mul(invFact[i-1], inv[i]);
    }
}

const ul block = 320;
struct Query {
    ul l, r, id;
};

bool compare(Query& a, Query& b) {
    ul ba = a.l / block, bb = b.l / block;
    if (ba != bb) return ba < bb;
    return (ba & 1) ? (a.r < b.r) : (a.r > b.r);
}

ul nums[N], n, q;
ul ans[N], freq[N], res = 0, sz = 0;

void add_val(ul x) {
    x = nums[x];
    if (sz == 0) {
        sz++; freq[x]++;
        return;
    }
    res = sub(res, mul(mul(freq[x] , sub(freq[x] , 1)) , fact[sz - 1]));
    res = mul(res, sz);
    freq[x]++;
    res = add(res, mul(mul(freq[x] , (freq[x] - 1)) , fact[sz]));
    sz++;
}

void remove_val(ul x) {
    x = nums[x];
    if (sz == 1) {
        sz--; freq[x]--;
        return;
    }
    sz--;
    res = sub(res, mul(mul(freq[x] , (freq[x] - 1)) , fact[sz]));
    freq[x]--;
    res = mul(res, inv[sz]);
    res = add(res, mul(mul(freq[x] , sub(freq[x] , 1)) , fact[sz - 1]));
}

vector<Query> queries;
void Mo() {
    sort(all(queries), compare);

    ul mo_left = 0, mo_right = -1;
    for (auto& cur : queries) {
        ul l = cur.l, r = cur.r, id = cur.id;
        while (mo_right < r) add_val(++mo_right);
        while (mo_left > l) add_val(--mo_left);
        while (mo_right > r) remove_val(mo_right--);
        while (mo_left < l) remove_val(mo_left++);
        
        ans[id] = res;
    }
}

void solve() {
    cin >> n >> q;
    for (ul i=0; i<n; i++) {
        cin >> nums[i];
        nums[i] = spf[nums[i]];
    }
    queries.resize(q);
    vector<ul>szs(q);
    for (ul i=0; i<q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--; queries[i].r--;
        queries[i].id = i;
        szs[i] = queries[i].r - queries[i].l + 1;
    }
    
    Mo();

    for (ul i=0; i<q; i++) {
        cout << mul(ans[i], invFact[szs[i]]) << endl;
    }
}

ul32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sieve();
    ul t = 1;
    while (t--) solve();
}