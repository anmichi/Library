// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/point_add_rectangle_sum
#include "../../Data-Structure/WaveletMatrixBIT.hpp"
void solve() {
    int n, q;
    cin >> n >> q;
    vector<tuple<int, int, int>> ps(n);
    for (auto& [x, y, w] : ps) cin >> x >> y >> w;
    vector<tuple<int, int, int, int, int>> qs(q);
    for (auto& [t, a, b, c, d] : qs) {
        cin >> t;
        if (t == 0) {
            cin >> a >> b >> c;
            ps.push_back({a, b, c});
        } else
            cin >> a >> b >> c >> d;
    }
    vector<pair<int, int>> p(ps.size());
    for (int i = 0; i < ps.size(); i++) p[i] = {get<0>(ps[i]), i};
    sort(p.begin(), p.end());
    vector<int> xs(ps.size());
    for (int i = 0; i < ps.size(); i++) {
        xs[i] = p[i].first;
        get<0>(ps[p[i].second]) = i;
    }
    vector<int> y(ps.size());
    vector<long long> w(ps.size());
    for (int i = 0; i < ps.size(); i++) {
        y[get<0>(ps[i])] = get<1>(ps[i]);
        if (i < n) w[get<0>(ps[i])] = get<2>(ps[i]);
    }
    CompressedWaveletMatrixBIT<int, 18, long long> wm(y, w);
    int it = n;
    for (auto& [t, l, d, r, u] : qs) {
        if (t == 0) {
            wm.add(get<0>(ps[it]), get<2>(ps[it]));
            it++;
        } else {
            l = lower_bound(xs.begin(), xs.end(), l) - xs.begin();
            r = lower_bound(xs.begin(), xs.end(), r) - xs.begin();
            cout << wm.rect_sum(l, r, d, u) << "\n";
        }
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}