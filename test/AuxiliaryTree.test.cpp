#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0439"
#include "../AuxiliaryTree.cpp"

#define rep(i, n) for (int i = 0; i < n; i++)
template <class T, class U>
inline bool chmin(T& a, U b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }
    vector<vector<int>> g(n);
    rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auxiliary_tree aux_tree(g);
    vector<vector<int>> vec(n);
    rep(i, n) vec[a[i]].push_back(i);
    vector<int> dist(n), idx(n);
    vector<int> ans(n, 1000000000);
    rep(color, n) {
        if (vec[color].empty()) continue;
        auto [root, vs] = aux_tree.query(vec[color]);
        using P = pair<int, int>;
        priority_queue<P, vector<P>, greater<P>> que;
        for (auto v : vs) dist[v] = n, idx[v] = -1;
        for (int s : vec[color]) dist[s] = 0, idx[s] = s, que.push({dist[s], s});
        while (!que.empty()) {
            auto [d, v] = que.top();
            que.pop();
            if (dist[v] != d) continue;
            for (auto u : aux_tree.G[v]) {
                int c = abs(aux_tree.depth[u] - aux_tree.depth[v]);
                if (chmin(dist[u], d + c)) {
                    idx[u] = idx[v];
                    que.push({dist[u], u});
                }
            }
        }
        for (int v : vs) {
            for (int u : aux_tree.G[v]) {
                if (idx[v] == idx[u]) continue;
                chmin(ans[idx[v]], aux_tree.dist(idx[v], idx[u]));
                chmin(ans[idx[u]], aux_tree.dist(idx[v], idx[u]));
            }
        }
        aux_tree.clear(vs);
    }
    rep(i, n) cout << ans[i] << endl;
}