#include <bits/stdc++.h>
using namespace std;
struct lca_tree {
    int n, size;
    vector<vector<int>> par;
    vector<int> depth;
    lca_tree(vector<vector<int>> g, int root = 0) : n((int)g.size()), size(log2(n) + 2), par(size, vector<int>(n, -1)), depth(vector<int>(n, n)) {
        queue<int> que;
        depth[root] = 0;
        que.push(root);
        while (!que.empty()) {
            int p = que.front();
            que.pop();
            for (int i : g[p]) {
                if (depth[i] > depth[p] + 1) {
                    depth[i] = depth[p] + 1;
                    par[0][i] = p;
                    que.push(i);
                }
            }
        }
        for (int k = 0; k < size - 1; k++) {
            for (int i = 0; i < n; i++) {
                if (par[k][i] == -1)
                    par[k + 1][i] = -1;
                else
                    par[k + 1][i] = par[k][par[k][i]];
            }
        }
    }
    int query(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);
        for (int k = size - 1; k >= 0; k--) {
            if (((depth[v] - depth[u]) >> k) & 1) v = par[k][v];
            if (u == v) return u;
        }
        for (int k = size - 1; k >= 0; k--) {
            if (par[k][u] != par[k][v]) {
                u = par[k][u];
                v = par[k][v];
            }
        }
        return par[0][u];
    }
    int dist(int u, int v) {
        int l = query(u, v);
        return depth[u] + depth[v] - 2 * depth[l];
    }
};
