#include <bits/stdc++.h>
using namespace std;

// Standard DSU: Fast, flattens tree, loses structure.
struct DSU {
    vector<int> parent, sz;
    DSU(int n) { // O(n)
        parent.resize(n + 1);
        sz.assign(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int u) { // O(alpha(n))
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    bool unite(int u, int v) { // O(alpha(n)) 
        u = find(u), v = find(v);
        if (u != v) {
            if (sz[u] < sz[v]) swap(u, v);
            parent[v] = u;
            sz[u] += sz[v];
            return true;
        }
        return false;
    }
};

// Weighted DSU: Slower, keeps tree structure for point inheritance.
struct Weighted_DSU {
    vector<int> parent, sz, val;
    Weighted_DSU(int n) { // O(n)
        parent.resize(n + 1);
        sz.assign(n + 1, 1);
        val.assign(n + 1, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int u) { // O(log n)
        if (parent[u] == u) return u;
        return find(parent[u]);
    }
    void join_sets(int u, int v) { // O(log n)
        u = find(u), v = find(v);
        if (u != v) {
            if (sz[u] < sz[v]) swap(u, v);
            parent[v] = u;
            sz[u] += sz[v];
            val[v] -= val[u];
        }
    }
    void add_to_set(int u, int x) { // O(log n)
        val[find(u)] += x;
    }
    int get_value(int u) { // O(log n) 
        if (parent[u] == u) return val[u];
        return val[u] + get_value(parent[u]);
    }
};