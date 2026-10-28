#include <bits/stdc++.h>
using namespace std;
// op(a,b) : aを作用させたあとbを作用させる
template <class S, auto op, auto e, bool commutative = false>
struct dual_segtree {
    int n = 0, sz = 1, log = 0;
    vector<S> d;
    dual_segtree() = default;
    explicit dual_segtree(int n) : dual_segtree(vector<S>(n, e())) {}
    explicit dual_segtree(const vector<S>& a) : n(int(a.size())) {
        while (sz < n) sz <<= 1, log++;
        d.assign(2 * sz, e());
        for (int i = 0; i < n; i++) d[sz + i] = a[i];
    }
    void apply(int l, int r, S x) {
        assert(0 <= l && l <= r && r <= n);
        if (l == r) return;
        l += sz, r += sz;
        if constexpr (!commutative) {
            for (int i = log; i >= 1; i--) {
                if (((l >> i) << i) != l) push(l >> i);
                if (((r >> i) << i) != r) push((r - 1) >> i);
            }
        }
        while (l < r) {
            if (l & 1) d[l] = op(d[l], x), l++;
            if (r & 1) --r, d[r] = op(d[r], x);
            l >>= 1, r >>= 1;
        }
    }
    void apply(int p, S x) { apply(p, p + 1, x); }
    S get(int p) const {
        assert(0 <= p && p < n);
        p += sz;
        S res = d[p];
        for (p >>= 1; p >= 1; p >>= 1) res = op(res, d[p]);
        return res;
    }
    void set(int p, S x) {
        assert(0 <= p && p < n);
        p += sz;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
    }
    vector<S> get_all() {
        for (int k = 1; k < sz; k++) push(k);
        return vector<S>(d.begin() + sz, d.begin() + sz + n);
    }

   private:
    void push(int k) {
        d[2 * k] = op(d[2 * k], d[k]);
        d[2 * k + 1] = op(d[2 * k + 1], d[k]);
        d[k] = e();
    }
};
