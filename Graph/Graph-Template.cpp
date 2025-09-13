#pragma once
#include <bits/stdc++.h>
using namespace std;
template <class T = int, bool Directed = false>
struct Graph {
    struct Edge {
        int from, to, idx;
        T cost;
        operator int() const { return to; }
    };
    vector<vector<Edge>> g;
    int es;
    Graph() = default;
    explicit Graph(int n) : g(n), es(0) {}
    int size() const { return int(g.size()); }
    void add_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, es, cost);
        if (!Directed) g[to].emplace_back(to, from, es, cost);
        es++;
    }
    void read(int m = -1, int index = 1, bool weighted = false) {
        if (m == -1) {
            assert(!g.empty());
            m = int(g.size()) - 1;
        }
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a -= index, b -= index;
            T c = T(1);
            if (weighted) cin >> c;
            add_edge(a, b, c);
        }
    }
    vector<Edge> &operator[](const int &k) { return g[k]; }
};
