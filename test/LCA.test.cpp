// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/lca
#include "../LCA.cpp"
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    lca_tree lt(g);
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << lt.lca(u, v) << "\n";
    }
}