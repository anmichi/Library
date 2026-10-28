// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/point_set_range_composite
#include "ds/segtree_optional.hpp"
constexpr long long MOD = 998244353;
using F = pair<long long, long long>;
F op(F f, F g) { return {f.first * g.first % MOD, (g.first * f.second + g.second) % MOD}; }
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<F> a(n);
    for (auto& [x, y] : a) cin >> x >> y;
    segtree_optional<F, op> seg(a);
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int p;
            long long c, d;
            cin >> p >> c >> d;
            seg.set(p, {c, d});
        } else {
            int l, r;
            long long x;
            cin >> l >> r >> x;
            F f = seg.prod(l, r);
            cout << (f.first * x + f.second) % MOD << "\n";
        }
    }
}
