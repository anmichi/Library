#include <bits/stdc++.h>
using namespace std;
struct UnionFind {
    vector<int> par, siz, es;
    UnionFind(int x) {
        par.resize(x);
        siz.resize(x);
        es.resize(x);
        for (int i = 0; i < x; i++) {
            par[i] = i;
            siz[i] = 1;
            es[i] = 0;
        }
    }
    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) {
            es[x]++;
            return;
        }
        if (siz[x] < siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        es[x] += es[y] + 1;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    int size(int x) { return siz[find(x)]; }
    int edges(int x) { return es[find(x)]; }
};