#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"
#include "../TwoEdgeConnectedComponents.cpp"
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    TwoEdgeConnectedComponents G(g);
    auto components = G.components();
    cout << components.size() << endl;
    for (auto vec : components) {
        cout << vec.size();
        for (auto v : vec) cout << " " << v;
        cout << "\n";
    }
}