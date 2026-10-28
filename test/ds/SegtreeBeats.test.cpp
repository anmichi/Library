// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
#include <bits/stdc++.h>
#include "ds/segtree_beats.hpp"
using namespace std;
using namespace chmin_chmax_add_sum;
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (auto& x : a) cin >> x;
    Seg seg(vector<S>(a.begin(), a.end()));
    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 3) {
            cout << seg.prod(l, r).sum << "\n";
            continue;
        }
        long long b;
        cin >> b;
        if (t == 0) seg.apply(l, r, F::chmin(b));
        if (t == 1) seg.apply(l, r, F::chmax(b));
        if (t == 2) seg.apply(l, r, F::add(b));
    }
}
