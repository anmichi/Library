#include "../../Graph/DominatorTree.cpp"
// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/dominatortree

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, root;
    cin >> n >> m >> root;
    vector<vector<int>> g(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    DominatorTree dom(g, root);
    rep(i, n) cout << dom[i] << " ";
    cout << endl;
}