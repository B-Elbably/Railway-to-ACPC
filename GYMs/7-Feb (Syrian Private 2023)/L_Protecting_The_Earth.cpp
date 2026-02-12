#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int count(int r){
    int rr = r * r;
    int ans = sqrt(rr) * 2 + 1;
    for(int x = 1; x <= r; x++){
        int y = sqrt(rr - x * x);
        ans += 4*y + 2; 
    }
    return ans;
}

void solve(){
    int k; cin >> k;
    int l = 1, r = 1e5;
    while(l < r){
        int mid = (l + r) / 2;
        if(count(mid) >= k) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}

// x^2 + y^2 <= r^2
// y^2 
