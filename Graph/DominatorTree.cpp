#include "../template.cpp"
struct DominatorTree {
    vector<vector<int>> g, rg;  // directed
    DominatorTree(vector<vector<int>> g, int root = 0) : g(g) {
        int n = int(g.size());
        par.assign(n, 0);
        idom.assign(n, -1);
        semi.assign(n, -1);
        ord.reserve(n);
        rg.resize(n);
        UnionFind uf(semi);

        dfs(root);
        for (int i = 0; i < n; i++) {
            for (auto &to : g[i]) {
                if (~semi[i]) rg[to].push_back(i);
            }
        }

        vector<vector<int>> bucket(n);
        vector<int> U(n);
        for (int i = (int)ord.size() - 1; i >= 0; i--) {
            int x = ord[i];
            for (int v : rg[x]) {
                v = uf.eval(v);
                if (semi[x] > semi[v]) semi[x] = semi[v];
            }
            bucket[ord[semi[x]]].emplace_back(x);
            for (int v : bucket[par[x]]) U[v] = uf.eval(v);
            bucket[par[x]].clear();
            uf.link(par[x], x);
        }
        for (int i = 1; i < (int)ord.size(); i++) {
            int x = ord[i], u = U[x];
            idom[x] = semi[x] == semi[u] ? semi[x] : idom[u];
        }
        for (int i = 1; i < (int)ord.size(); i++) {
            int x = ord[i];
            idom[x] = ord[idom[x]];
        }
        idom[root] = root;
    }

    int operator[](const int &k) const { return idom[k]; }

    struct UnionFind {
        const vector<int> &semi;
        vector<int> par, m;
        UnionFind(const vector<int> &semi) : semi(semi), par(semi.size()), m(semi.size()) {
            iota(begin(par), end(par), 0);
            iota(begin(m), end(m), 0);
        }

        int find(int v) {
            if (par[v] == v) return v;
            int r = find(par[v]);
            if (semi[m[v]] > semi[m[par[v]]]) m[v] = m[par[v]];
            return par[v] = r;
        }

        int eval(int v) {
            find(v);
            return m[v];
        }

        void link(int p, int c) { par[c] = p; }
    };

    vector<int> ord, par;
    vector<int> idom, semi;

    void dfs(int idx) {
        semi[idx] = (int)ord.size();
        ord.emplace_back(idx);
        for (auto &to : g[idx]) {
            if (~semi[to]) continue;
            dfs(to);
            par[to] = idx;
        }
    }
};