#include <bits/stdc++.h>
using namespace std;
template <class S, auto op>
struct segtree_optional {
    using D = optional<S>;
    int n = 0, sz = 1;
    vector<D> d;
    segtree_optional() = default;
    explicit segtree_optional(int n) : n(n) {
        while (sz < n) sz <<= 1;
        d.assign(2 * sz, nullopt);
    }
    explicit segtree_optional(const vector<S>& a) : segtree_optional(int(a.size())) {
        for (int i = 0; i < n; i++) d[sz + i] = a[i];
        for (int i = sz - 1; i >= 1; i--) d[i] = merge(d[2 * i], d[2 * i + 1]);
    }
    void set(int p, const S& x) {
        assert(0 <= p && p < n);
        p += sz;
        d[p] = x;
        for (p >>= 1; p >= 1; p >>= 1) d[p] = merge(d[2 * p], d[2 * p + 1]);
    }
    S get(int p) const {
        assert(0 <= p && p < n && d[p + sz]);
        return *d[p + sz];
    }
    S prod(int l, int r) const {
        assert(0 <= l && l < r && r <= n);
        D sml, smr;
        for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
            if (l & 1) sml = merge(sml, d[l++]);
            if (r & 1) smr = merge(d[--r], smr);
        }
        D res = merge(sml, smr);
        assert(res);
        return *res;
    }
    S all_prod() const {
        assert(d[1]);
        return *d[1];
    }
    template <class G>
    int max_right(int l, G g) const {
        assert(0 <= l && l <= n);
        if (l == n) return n;
        l += sz;
        D sm;
        do {
            while (!(l & 1)) l >>= 1;
            if (!ok(merge(sm, d[l]), g)) {
                while (l < sz) {
                    l <<= 1;
                    if (ok(merge(sm, d[l]), g)) sm = merge(sm, d[l++]);
                }
                return l - sz;
            }
            sm = merge(sm, d[l++]);
        } while ((l & -l) != l);
        return n;
    }
    template <class G>
    int min_left(int r, G g) const {
        assert(0 <= r && r <= n);
        if (r == 0) return 0;
        r += sz;
        D sm;
        do {
            r--;
            while (r > 1 && (r & 1)) r >>= 1;
            if (!ok(merge(d[r], sm), g)) {
                while (r < sz) {
                    r = 2 * r + 1;
                    if (ok(merge(d[r], sm), g)) sm = merge(d[r--], sm);
                }
                return r + 1 - sz;
            }
            sm = merge(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

   private:
    static D merge(const D& a, const D& b) {
        if (!a) return b;
        if (!b) return a;
        return op(*a, *b);
    }
    template <class G>
    static bool ok(const D& x, G& g) {
        return !x || g(*x);
    }
};
