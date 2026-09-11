#pragma once
#include <bits/stdc++.h>
using namespace std;
struct LowLink {
    vector<vector<int>> g;
    vector<int> ord, low, out;
    vector<bool> used;
    vector<pair<int, int>> bridge;
    vector<pair<int, int>> articulation;
    int unions;
    LowLink(vector<vector<int>> g) : g(g) {
        int n = (int)g.size();
        ord.resize(n);
        low.resize(n);
        out.resize(n);
        used.resize(n);
        unions = 0;
        int t = 0;
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                dfs(i, t, -1);
                unions++;
            }
        }
    }
    void dfs(int v, int &t, int par) {
        used[v] = true;
        ord[v] = t++, low[v] = ord[v];
        int cnt = 0;
        bool par_back = false;
        for (int to : g[v]) {
            if (!used[to]) {
                dfs(to, t, v);
                low[v] = min(low[v], low[to]);
                if (ord[v] < low[to]) bridge.push_back(minmax(v, to));
                if (ord[v] <= low[to]) cnt++;
            } else if (to != par || par_back) {
                low[v] = min(low[v], ord[to]);
            } else
                par_back = true;
        }
        if (par != -1) cnt++;
        if (cnt >= 2) articulation.push_back({v, cnt});
        out[v] = t;
    }
};