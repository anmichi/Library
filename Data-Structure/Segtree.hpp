#include <bits/stdc++.h>
using namespace std;
template <class S, auto op, auto e>
struct segtree {
    int _n, sz = 1;
    vector<S> dat;
    segtree(int n) : segtree(vector<S>(n, e())) {}
    segtree(vector<S> a) : _n(int(a.size())) {
        while (sz < _n) sz <<= 1;
        dat.resize(2 * sz, e());
        for (int i = 0; i < _n; i++) dat[sz + i] = a[i];
        for (int i = sz - 1; i >= 1; i--) dat[i] = op(dat[2 * i], dat[2 * i + 1]);
    }
    void set(int p, S x) {
        p += sz;
        dat[p] = x;
        while (p > 1) {
            p >>= 1;
            dat[p] = op(dat[2 * p], dat[2 * p + 1]);
        }
    }
    S prod(int l, int r) {
        l += sz, r += sz;
        S vl = e(), vr = e();
        while (l < r) {
            if (l & 1) vl = op(vl, dat[l++]);
            if (r & 1) vr = op(dat[--r], vr);
            l >>= 1, r >>= 1;
        }
        return op(vl, vr);
    }
    template <class F>
    int max_right(int l, F f) {
        assert(f(e()));
        if (l == _n) return _n;
        l += sz;
        S sm = e();
        do {
            while (!(l & 1)) l >>= 1;
            if (!f(op(sm, dat[l]))) {
                while (l < sz) {
                    l = 2 * l;
                    if (f(op(sm, dat[l]))) {
                        sm = op(sm, dat[l]);
                        l++;
                    }
                }
                return l - sz;
            }
            sm = op(sm, dat[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }
    template <class F>
    int min_left(int r, F f) {
        assert(f(e()));
        if (r == 0) return 0;
        r += sz;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r & 1)) r >>= 1;
            if (!f(op(dat[r], sm))) {
                while (r < sz) {
                    r = 2 * r + 1;
                    if (f(op(dat[r], sm))) {
                        sm = op(dat[r], sm);
                        r--;
                    }
                }
                return r + 1 - sz;
            }
            sm = op(dat[r], sm);
        } while ((r & -r) != r);
        return 0;
    }
};