#include <bits/stdc++.h>
using namespace std;

/*
gen_tree.cpp - Random Tree Generator with multiple modes

Modes:
1 = Fully random tree with random vertex relabeling
2 = Balanced binary tree (parent = floor(i/2))
3 = Star tree (all nodes connect to root 1)
4 = Chain (path) tree (edges: 1-2, 2-3, ..., n-1 - n)
5 = Caterpillar tree (spine + leaves)

Each run randomly picks one mode to generate diverse test cases.
Node count n is random between 2 and 20.
*/

int randInt(int l, int r) {
    return l + rand() % (r - l + 1);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: ./gen_tree <seed>\n";
        return 1;
    }
    srand(atoi(argv[1]));

    int n = randInt(2, 20);
    int mode = randInt(1, 5);

    printf("%d\n", n);

    if (mode == 1) {
        // Fully random tree with random labeling
        vector<pair<int,int>> edges;
        for (int i = 2; i <= n; i++) {
            edges.emplace_back(randInt(1, i - 1), i);
        }

        vector<int> perm(n);
        for (int i = 0; i < n; i++) perm[i] = i + 1;
        random_shuffle(perm.begin(), perm.end());
        random_shuffle(edges.begin(), edges.end());

        for (auto &e : edges) {
            int a = perm[e.first - 1];
            int b = perm[e.second - 1];
            if (randInt(0, 1)) swap(a, b);
            printf("%d %d\n", a, b);
        }

    } else if (mode == 2) {
        // Balanced binary tree
        for (int i = 2; i <= n; i++) {
            printf("%d %d\n", i / 2, i);
        }

    } else if (mode == 3) {
        // Star tree
        for (int i = 2; i <= n; i++) {
            printf("1 %d\n", i);
        }

    } else if (mode == 4) {
        // Chain tree
        for (int i = 2; i <= n; i++) {
            printf("%d %d\n", i - 1, i);
        }

    } else {
        // Caterpillar tree
        int spine_len = max(2, n / 2);
        for (int i = 2; i <= spine_len; i++) {
            printf("%d %d\n", i - 1, i);
        }
        for (int i = spine_len + 1; i <= n; i++) {
            int parent = randInt(1, spine_len);
            printf("%d %d\n", parent, i);
        }
    }

    // Print mode info to stderr for debugging (optional)
    const char* mode_names[] = {"", "Random", "Balanced Binary", "Star", "Chain", "Caterpillar"};
    cerr << "Generated mode: " << mode_names[mode] << "\n";

    return 0;
}
