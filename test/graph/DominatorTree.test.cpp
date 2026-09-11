#include "graph/dominator_tree.hpp"
// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/dominatortree

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, root;
    cin >> n >> m >> root;
    vector<vector<int>> g(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    DominatorTree dom(g, root);
    for (int i = 0; i < n; i++) cout << dom[i] << " ";
    cout << endl;
}