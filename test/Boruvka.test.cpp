// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/minimum_spanning_tree
#include "boruvka.hpp"
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