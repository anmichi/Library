#include <bits/stdc++.h>
#include "SparseTable.cpp"
using namespace std;
pair<int, int> lcatree_op(pair<int, int> a, pair<int, int> b) { return min(a, b); }
pair<int, int> lcatree_e() { return {1000000000, -1}; }
struct lca_tree {
    int n, size;
    vector<int> in, ord, depth;
    sparsetable<pair<int, int>, lcatree_op, lcatree_e> st;
    lca_tree(vector<vector<int>> g, int root = 0) : n((int)g.size()), size(log2(n) + 2), in(n), depth(n, n) {
        depth[root] = 0;
        function<void(int, int)> dfs = [&](int v, int p) {
            in[v] = (int)ord.size();
            ord.push_back(v);
            for (int u : g[v]) {
                if (u == p) continue;
                if (depth[u] > depth[v] + 1) {
                    depth[u] = depth[v] + 1;
                    dfs(u, v);
                    ord.push_back(v);
                }
            }
        };
        dfs(root, -1);
        vector<pair<int, int>> vec((int)ord.size());
        for (int i = 0; i < (int)ord.size(); i++) {
            vec[i] = make_pair(depth[ord[i]], ord[i]);
        }
        st = vec;
    }
    int lca(int u, int v) {
        if (in[u] > in[v]) swap(u, v);
        if (u == v) return u;
        return st.query(in[u], in[v]).second;
    }
    int dist(int u, int v) {
        int l = lca(u, v);
        return depth[u] + depth[v] - 2 * depth[l];
    }
};
