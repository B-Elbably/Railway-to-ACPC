#include <bits/stdc++.h>
using namespace std;

vector<int> res, ele;
// int level = 0; // track recursion depth

void backtrack() {
    // indentation for simulation
    // string indent(level * 2, ' ');

    if (ele.empty()) {
        // cout << indent << "Solution found: ";
        for (int x : res) { cout << x << " "; }
        cout << "\n";
        exit(0);
    }

    for (int i = ele.size() - 1; i >= 0; --i) {
        int x = ele[i];

        if (res.empty() || abs(res.back() - x) != 1) {
            // cout << indent << "Trying " << x << " with res = [";
            // for (int v : res) cout << v << " ";
            // cout << "]\n";  

            ele.erase(ele.begin() + i);
            res.push_back(x);
            // level++;

            backtrack();

            // level--;
            res.pop_back();
            ele.insert(ele.begin() + i, x);

            // cout << indent << "Backtracking from " << x << " with res = [";
            // for (int v : res) cout << v << " ";
            // cout << "]\n";
        } else {
            // cout << indent << "Skipping " << x << " because |last - x| == 1\n";
        }
    }
}

int main() {
    int n;
    cin >> n;

    if (n == 2 || n == 3) {
        cout << "NO SOLUTION" << '\n';
        return 0;
    }

    for (int i = n; i >= 1; i--) { ele.push_back(i); }

    backtrack();
}
