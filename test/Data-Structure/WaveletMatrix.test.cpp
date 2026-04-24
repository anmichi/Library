// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/range_kth_smallest
#include "../../Data-Structure/WaveletMatrix.hpp"
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    CompressedWaveletMatrix<int, 18> wm(a);
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << wm.kth_smallest(l, r, k) << "\n";
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}