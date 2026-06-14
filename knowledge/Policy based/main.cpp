#include <bits/stdc++.h>
// policy based data structure
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// ! ===================
// ordered_set
template<typename T>
using ordered_set = tree<T, null_type, less<T>,
                                    rb_tree_tag,
                                    tree_order_statistics_node_update>;

// ! ===================                                
// ordered_multiset
template<typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>,
                                    rb_tree_tag,
                                    tree_order_statistics_node_update>;

// ! ===================                                
// priority_queue
template<typename T>
using min_heap = __gnu_pbds::priority_queue<T, greater<T>, pairing_heap_tag>;

// ! ===================                                
// gb hash
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
                    chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

gp_hash_table<int, int, custom_hash> table;

// pair hash
struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ (hash2 << 1);
    }
};

gp_hash_table<pair<int, int>, int, pair_hash> pair_table;


// ! ===================
// trie
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> Trie;