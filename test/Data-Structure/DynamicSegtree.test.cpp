// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/point_set_range_composite_large_array
#include "../../Data-Structure/DynamicSegtree.hpp"
using ll = long long;
using S = pair<ll, ll>;
const ll mod = 998244353;
S op(S a, S b) { return S{a.first * b.first % mod, (a.second * b.first + b.second) % mod}; }
S e() { return S{1, 0}; }
void solve() {
    int n, q;
    cin >> n >> q;
    dynamic_segtree<S, op, e, false> seg(0, n);
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int a, b, c;
            cin >> a >> b >> c;
            seg.set(a, S{b, c});
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            auto [b, c] = seg.prod(l, r);
            cout << (b * x + c) % mod << "\n";
        }
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}