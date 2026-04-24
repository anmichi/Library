// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/rectangle_sum
#include "../../Data-Structure/WaveletMatrixRectSum.hpp"
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> xs;
    vector<tuple<int, int, int>> ps(n);
    for (auto& [x, y, w] : ps) {
        cin >> x >> y >> w;
        xs.push_back(x);
    }
    sort(ps.begin(), ps.end());
    sort(xs.begin(), xs.end());
    vector<long long> y(n), w(n);
    for (int i = 0; i < n; i++) {
        int hoge;
        tie(hoge, y[i], w[i]) = ps[i];
    }
    CompressedWaveletMatrixRectSum<long long, 18, long long> wm(y, w);
    while (q--) {
        int l, d, r, u;
        cin >> l >> d >> r >> u;
        l = lower_bound(xs.begin(), xs.end(), l) - xs.begin();
        r = lower_bound(xs.begin(), xs.end(), r) - xs.begin();
        cout << wm.rect_sum(l, r, d, u) << "\n";
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}