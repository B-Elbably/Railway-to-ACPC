#include <iostream>

using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int K, N;
    cin >> K >> N;
    while (N--) {
        int X;
        cin >> X;

        int sm = 0;
        int ans = 0;

        for (int v = 1; ; v++) {
            sm += v;
            ans++;
            if (sm >= K) {
                cout << ans << "\n";
                break;
            }
            
            if (v >= X) {
                sm += v;
                ans++;
                if (sm >= K) {
                    cout << ans << "\n";
                    break;
                }
            }
        }
    }

    return 0;
}