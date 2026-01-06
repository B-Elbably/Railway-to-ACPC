#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> weights(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end()); // Sort the weights

    int min_instability = INT_MAX;

    // Try every pair of people as the ones in the single kayaks
    for (int i = 0; i < 2 * n; ++i) {
        for (int j = i + 1; j < 2 * n; ++j) {
            vector<bool> used(2 * n, false);
            used[i] = used[j] = true;
            int instability = 0;

            // Now, pair the remaining people into tandem kayaks
            for (int k = 0; k < 2 * n; ++k) {
                if (!used[k]) {
                    for (int l = k + 1; l < 2 * n; ++l) {
                        if (!used[l]) {
                            used[k] = used[l] = true;
                            instability += abs(weights[k] - weights[l]);
                            break;
                        }
                    }
                }
            }

            // Check if this pairing results in a smaller instability
            min_instability = min(min_instability, instability);
        }
    }

    cout << min_instability << endl;
    return 0;
}
