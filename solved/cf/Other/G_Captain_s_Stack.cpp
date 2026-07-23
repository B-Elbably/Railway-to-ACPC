#include <bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 998244353;

int add(int a, int b) {
    return (a + b) % mod;
}

int sub(int a, int b) {
    return (a - b + mod) % mod;
}

int mul(int a, int b) {
    return (a * b) % mod;
}

int fpow(int a, int b) {
    if (!b) return 1;
    int x = fpow(a, b >> 1);
    x = mul(x, x);
    if (b & 1) x = mul(x, a);
    return x;
}

int divide(int a, int b) {
    return mul(a, fpow(b, mod - 2));
}

signed main(){
    std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
    int n; 
    cin >> n; 
    int sum = 0; 
    deque<int> deq;
    int N = n + 10; 
    int ok = 0;
    for(int i = 0 ; i < n ; i++){
        string s;
        cin >> s; 
        if (s == "Push"){
            int x; 
            cin >> x; 
            sum = add(sum , x);
            deq.push_back(x);
        }
        else if (s == "Repeat"){
            sum = mul(sum , 2);
            // cout << sum << endl;
            if (ok) {
                cout << sum << endl;
                continue;
            }
            int s = deq.size();
            vector<int> tmp;             
            for(int j = 0; j < s; j++){
                int xx = deq.front(); deq.pop_front();
                tmp.push_back(xx);
            }
            for (int x: tmp) deq.push_back(x);
            for (int x: tmp) deq.push_back(x);
            ok |= deq.size() >= n;
        }
        else{
            int xx = deq.back();
            deq.pop_back();
            sum = sub(sum , xx);
        }
        sum %= mod;
        cout << sum << '\n'; 
    }
}