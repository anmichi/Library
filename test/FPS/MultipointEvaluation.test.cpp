// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/multipoint_evaluation
#include "../../FPS/Multipoint-Evaluation.hpp"
using mint = atcoder::modint998244353;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<mint> c(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        c[i] = a;
    }
    vector<mint> p(m);
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        p[i] = a;
    }
    vector<mint> ans = MultiEval(c, p);
    for (auto& x : ans) cout << x.val() << " ";
    cout << endl;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}