// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/staticrmq
#include "../../Data-Structure/SparseTable.hpp"
int op(int a, int b) { return min(a, b); }
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    disjointsparsetable<int, op> st(a);
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << st.query(l, r) << "\n";
    }
}
