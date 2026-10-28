// competitive-verifier: PROBLEM https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
#include "ds/dual_segtree.hpp"
long long op(long long a, long long b) { return a + b; }
long long e() { return 0; }
int main() {
    int n, q;
    cin >> n >> q;
    dual_segtree<long long, op, e, true> seg(n);
    while (q--) {
        int type;
        cin >> type;
        if (type == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            seg.apply(s - 1, t, x);
        } else {
            int k;
            cin >> k;
            cout << seg.get(k - 1) << "\n";
        }
    }
}
