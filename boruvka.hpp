#include <bits/stdc++.h>
using namespace std;
#include "unionfind.hpp"
template <class T, class F>
vector<tuple<int, int, T>> boruvka(int n, F f) {
    vector<tuple<int, int, T>> es;
    UnionFind uf(n);
    vector<int> comp(n), id(n);
    int k = n;
    while (k > 1) {
        fill(id.begin(), id.end(), -1);
        int cnt = 0;
        for (int v = 0; v < n; v++) {
            int r = uf.find(v);
            if (id[r] < 0) id[r] = cnt++;
            comp[v] = id[r];
        }
        const vector<int>& ccomp = comp;
        auto near = f(k, ccomp);
        vector<int> best(k, -1);
        for (int u = 0; u < n; u++) {
            if (near[u].second < 0) continue;
            assert(comp[u] != comp[near[u].second]);
            int& b = best[comp[u]];
            if (b < 0 || near[u].first < near[b].first) b = u;
        }
        int nk = k;
        for (int u : best) {
            if (u < 0) continue;
            auto [w, v] = near[u];
            if (uf.unite(u, v)) {
                es.emplace_back(u, v, w);
                nk--;
            }
        }
        if (k == nk) break;
        k = nk;
    }
    return es;
}
inline bool chmin(auto& a, const auto& b) { return a > b ? a = b, 1 : 0; }
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    using ll = long long;
    vector<tuple<int, int, pair<ll, int>>> es(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        es[i] = {u, v, {w, i}};
    }
    using T = pair<ll, int>;
    auto res = boruvka<T>(n, [&](int, auto& comp) {
        vector<pair<T, int>> near(n, {{LLONG_MAX, -1}, -1});
        for (auto [u, v, w] : es) {
            if (comp[u] == comp[v]) continue;
            chmin(near[u], pair{w, v});
            chmin(near[v], pair{w, u});
        }
        return near;
    });
    ll cost = 0;
    for (auto [u, v, w] : res) cost += w.first;
    cout << cost << endl;
    for (auto [u, v, w] : res) cout << w.second << " ";
    cout << endl;
}