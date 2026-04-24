// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/range_kth_smallest
#include "../../Data-Structure/DynamicSegtree.hpp"

int op(int a, int b) { return a + b; }
int e() { return 0; }
void solve() {
    int n, q;
    cin >> n >> q;
    dynamic_segtree<int, op, e, true> seg(0, 1e9 + 1);
    while (n--) {
        int a;
        cin >> a;
        seg.duplicate();
        seg.set(a, seg.get(a) + 1);
    }
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        int ok = 1e9 + 1, ng = -1;
        while (ok - ng > 1) {
            int x = (ok + ng) / 2;
            if (seg.prod(r, 0, x + 1) - seg.prod(l, 0, x + 1) >= k + 1)
                ok = x;
            else
                ng = x;
        }
        cout << ok << "\n";
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}