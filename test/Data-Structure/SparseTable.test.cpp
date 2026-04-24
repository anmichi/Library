// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/staticrmq
#include "../../Data-Structure/SparseTable.hpp"
int op(int a, int b) { return min(a, b); }
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    sparsetable<int, op> st(a);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << st.query(l, r) << "\n";
    }
}