#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<long long, int>, null_type, less<pair<long long, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class DynamicMergeSortTree {
    int n;
    vector<ordered_set> bit;
    vector<long long> arr;

    void add(int idx, long long val, int type) {
        for (; idx <= n; idx += idx & -idx) {
            if (type == 1) bit[idx].insert({val, idx});
            else bit[idx].erase({val, idx});
        }
    }

    int query_greater(int idx, long long val) {
        int ans = 0;
        for (; idx > 0; idx -= idx & -idx) {
            ans += bit[idx].size() - bit[idx].order_of_key({val, 1e9});
        }
        return ans;
    }
    
    int query_smaller(int idx, long long val) {
        int ans = 0;
        for (; idx > 0; idx -= idx & -idx) {
            ans += bit[idx].order_of_key({val, -1});
        }
        return ans;
    }

public:
    DynamicMergeSortTree(const vector<long long>& a) {
        n = a.size();
        arr = a;
        bit.resize(n + 1);
        for (int i = 0; i < n; i++) add(i + 1, arr[i], 1); 
    }

    void update(int idx, long long new_val) {
        if (arr[idx] == new_val) return;
        add(idx + 1, arr[idx], -1); 
        add(idx + 1, new_val, 1);    
        arr[idx] = new_val;
    }

    int greater_(int l, int r, long long val) {
        if (n == 0) return 0;
        return query_greater(r + 1, val) - query_greater(l, val);
    }
    
    int smaller_(int l, int r, long long val) {
        if (n == 0) return 0;
        return query_smaller(r + 1, val) - query_smaller(l, val);
    }
};