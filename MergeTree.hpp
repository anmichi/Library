#include <bits/stdc++.h>
using namespace std;
struct MergeTree {
    vector<int> par;
    vector<vector<int>> g;
    MergeTree(int x) {
        par.resize(x);
        g.resize(x);
        for (int i = 0; i < x; i++) par[i] = i;
    }
    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        int t = g.size();
        g.push_back({x, y});
        par[x] = par[y] = t;
        par.push_back(t);
        return true;
    }
    bool same(int x, int y) { return find(x) == find(y); }
};