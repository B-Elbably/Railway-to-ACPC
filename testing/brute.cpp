#include <bits/stdc++.h>
using namespace std;

int min_coins_brute(vector<int> a) {
    int n = a.size();
    vector<bool> blue(n, true);
    int coins = 0;

    while (any_of(blue.begin(), blue.end(), [](bool b){ return b; })) {
        for (int i = 0; i < n; i++) {
            if (blue[i]) {
                coins++;
                blue[i] = false;

                queue<int> q;
                q.push(i);

                while (!q.empty()) {
                    int idx = q.front(); q.pop();
                    for (int ni : {idx - 1, idx + 1}) {
                        if (ni >= 0 && ni < n && blue[ni] && a[idx] > 0) {
                            a[idx]--;
                            blue[ni] = false;
                            q.push(ni);
                        }
                    }
                }
                break;
            }
        }
    }

    return coins;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << min_coins_brute(a) << endl;
    return 0;
}
