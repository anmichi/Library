#include <vector>
#define reference1 "https://judge.yosupo.jp/submission/198015"
#define reference2 "https://atcoder.jp/contests/s8pc-4/submissions/51468320"
struct S {
    double dp;
    int cc;  // cnt_child
};
S dp[200010], dp2[200010];
std::vector<int> g[200010];
S merge(S a, S b) { return {a.dp + b.dp, a.cc + b.cc}; }
S fv(S x, int v) { return {x.cc == 0 ? 0 : (1 + x.dp / x.cc), 1}; }
S fe(S x, int ch) { return x; }
S e() { return S{0, 0}; }
void dfs1(int v, int p = -1) {
    dp[v] = e();
    for (int u : g[v]) {
        if (u != p) {
            dfs1(u, v);
            dp[v] = merge(dp[v], dp2[u]);
        }
    }
    dp2[v] = fe(fv(dp[v], v), v);
}
void dfs2(int v, int par = -1, S dp_par = e()) {
    int k = g[v].size();
    std::vector<S> c1(k + 1), c2(k + 1);
    // c1[i]:fold[0,i)
    // c2[i]:fold[i,k)
    c1[0] = c2[k] = e();
    for (int i = 0; i < k; i++) {
        int u = g[v][i];
        if (u == par) {
            S tmp = fe(fv(dp_par, par), par);
            c1[i + 1] = c2[i] = tmp;
            dp[v] = merge(dp[v], tmp);
        } else {
            c1[i + 1] = c2[i] = dp2[u];
        }
    }
    for (int i = 0; i < k; i++) c1[i + 1] = merge(c1[i + 1], c1[i]);
    for (int i = k - 1; i >= 0; i--) c2[i] = merge(c2[i], c2[i + 1]);
    for (int i = 0; i < k; i++) {
        int u = g[v][i];
        if (u != par) {
            dfs2(u, v, merge(c1[i], c2[i + 1]));
        }
    }
    dp[v] = fv(dp[v], v);
}