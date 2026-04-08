#include <vector>
using namespace std;
template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F (*composition)(F, F), F (*id)()>
struct lazy_segtree {
    int _n, sz = 1;
    vector<S> dat;
    vector<F> lazy;
    lazy_segtree(vector<S> a) : _n(int(a.size())) {
        while (sz < _n) sz <<= 1;
        dat.resize(sz * 2, e());
        lazy.resize(sz * 2, id());
        for (int i = 0; i < _n; i++) dat[sz + i] = a[i];
        for (int i = sz - 1; i >= 1; i--) dat[i] = op(dat[2 * i], dat[2 * i + 1]);
    }
    void eval(int k) {
        dat[k] = mapping(lazy[k], dat[k]);
        if (k < sz) {
            lazy[k * 2] = composition(lazy[k], lazy[k * 2]);
            lazy[k * 2 + 1] = composition(lazy[k], lazy[k * 2 + 1]);
        }
        lazy[k] = id();
    }
    void apply(int a, int b, F f, int k = 1, int l = 0, int r = -1) {
        eval(k);
        if (r == -1) r = sz;
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            lazy[k] = composition(f, lazy[k]);
            eval(k);
            return;
        }
        int m = (l + r) >> 1;
        apply(a, b, f, 2 * k, l, m);
        apply(a, b, f, 2 * k + 1, m, r);
        dat[k] = op(dat[2 * k], dat[2 * k + 1]);
    }
    S prod(int a, int b, int k = 1, int l = 0, int r = -1) {
        eval(k);
        if (r == -1) r = sz;
        if (r <= a || b <= l) return e();
        if (a <= l && r <= b) return dat[k];
        int m = (l + r) >> 1;
        S vl = prod(a, b, 2 * k, l, m);
        S vr = prod(a, b, 2 * k + 1, m, r);
        return op(vl, vr);
    }
};
