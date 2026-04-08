#pragma once
#include <bits/stdc++.h>
using namespace std;
template <class G>
struct HLD {
    G g;
    vector<int> sz, in, out, par, head, dep, ord;
    HLD(G &g, int root = 0)
        : g(g), sz((int)g.size()), in((int)g.size()), out((int)g.size()), par((int)g.size()), head((int)g.size(), root), dep((int)g.size()) {
        dfs_sz(root, -1);
        dfs_hld(root, -1);
    }
    void dfs_sz(int v, int p) {
        par[v] = p;
        sz[v] = 1;
        if (g[v].size() && g[v][0] == p) swap(g[v][0], g[v].back());
        for (auto &i : g[v]) {
            if (i != p) {
                dep[i] = dep[v] + 1;
                dfs_sz(i, v);
                sz[v] += sz[i];
                if (sz[g[v][0]] < sz[i]) swap(g[v][0], i);
            }
        }
    }
    void dfs_hld(int v, int p) {
        in[v] = ord.size();
        ord.push_back(v);
        for (auto i : g[v]) {
            if (i != p) {
                if (int(i) == int(g[v][0])) {
                    // Heavy
                    head[i] = head[v];
                } else {
                    // Light
                    head[i] = i;
                }
                dfs_hld(i, v);
            }
        }
        out[v] = ord.size();
    }
    int lca(int u, int v) {
        while (1) {
            if (in[u] > in[v]) swap(u, v);
            if (head[u] == head[v]) return u;
            v = par[head[v]];
        }
    }
    int dist(int u, int v) { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }
    int la(int v, int d) {
        while (v != -1) {
            int u = head[v];
            if (in[v] - d >= in[u]) return ord[in[v] - d];
            d -= in[v] - in[u] + 1, v = par[u];
        }
        return -1;
    }
    int jump(int from, int to, int d) {
        int l = lca(from, to);
        if (d <= dep[from] - dep[l]) return la(from, d);
        d -= dep[from] - dep[l];
        if (d <= dep[to] - dep[l]) return la(to, dep[to] - dep[l] - d);
        return -1;
    }
};