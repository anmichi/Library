#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
struct TwoEdgeConnectedComponents {
    int V;
    vector<vector<int>> g, new_g;
    vector<int> depth, imos, comp;
    vector<vector<int>> comps;
    TwoEdgeConnectedComponents(vector<vector<int>> g_) : V((int)g_.size()), g(g_), depth(V, -1), imos(V), comp(V, -1) {
        int t = -1;
        rep(i, V) {
            if (depth[i] == -1) {
                depth[i] = 0;
                dfs_init(i);
                comp[i] = ++t;
                comps.push_back({});
                new_g.push_back({});
                dfs(i, t);
            }
        }
    }
    void dfs_init(int v) {
        for (int u : g[v]) {
            if (depth[u] == -1) {
                depth[u] = depth[v] + 1;
                dfs_init(u);
                imos[v] += imos[u];
            } else if (depth[u] < depth[v])
                imos[u]--, imos[v]++;
        }
    }
    void dfs(int v, int &t) {
        comps[comp[v]].push_back(v);
        for (int u : g[v]) {
            if (depth[u] == depth[v] + 1 && comp[u] == -1) {
                if (imos[u] <= 1) {
                    comp[u] = ++t;
                    comps.push_back({});
                    new_g.push_back({});
                    new_g[comp[v]].push_back(comp[u]);
                } else
                    comp[u] = comp[v];
                dfs(u, t);
            }
        }
    }
    vector<vector<int>> components() { return comps; }
    vector<vector<int>> directed_forest() { return new_g; }
};